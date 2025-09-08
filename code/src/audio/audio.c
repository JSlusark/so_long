#include "audio.h"

static pid_t g_music_pid = -1;

static void reap(int sig)
{
	(void)sig;
	while (waitpid(-1, NULL, WNOHANG) > 0)
	{
	}
}

void audio_init(void)
{
	struct sigaction sa = {0};
	sa.sa_handler = reap;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_NOCLDSTOP;
	sigaction(SIGCHLD, &sa, NULL);
}

// Choose your player:
// macOS: "afplay" (built-in, WAV/MP3), Linux: "paplay" (PulseAudio, WAV/OGG) or "aplay" (ALSA, WAV)
#if defined(__APPLE__)
#define MUSIC_PLAYER "afplay"
#define SFX_PLAYER "afplay"
// static void silence_stdio(void)
// {
// 	int fd = open("/dev/null", O_RDWR);
// 	if (fd >= 0)
// 	{
// 		dup2(fd, STDOUT_FILENO);
// 		dup2(fd, STDERR_FILENO);
// 		if (fd > 2)
// 			close(fd);
// 	}
// }
static char *vol_arg(float v)
{
	static char b[16];
	if (v <= 0)
		v = 0.01f;
	if (v > 1)
		v = 1.0f;
	snprintf(b, sizeof b, "%.2f", v);
	return b;
}
#elif defined(__linux__)
#define MUSIC_PLAYER "paplay"
#define SFX_PLAYER "paplay"
static char *vol_arg(float v)
{
	(void)v;
	return NULL;
} // paplay volume via pactl; skip here
#endif

void start_music(const char *path, float volume)
{
	stop_music();
	pid_t pid = fork();
	if (pid == 0)
	{
#if defined(__APPLE__)
		// Loop music: restart on end using a tiny exec loop
		for (;;)
		{
			execlp(MUSIC_PLAYER, MUSIC_PLAYER, "-v", vol_arg(volume), path, (char *)NULL);
			_exit(1);
		}
#elif defined(__linux__)
		// paplay has no loop flag; simple restart loop
		for (;;)
		{
			execlp(MUSIC_PLAYER, MUSIC_PLAYER, path, (char *)NULL);
			_exit(1);
		}
#endif
	}
	else if (pid > 0)
	{
		g_music_pid = pid;
	}
}

void stop_music(void)
{
	if (g_music_pid > 0)
	{
		kill(g_music_pid, SIGTERM);
		waitpid(g_music_pid, NULL, 0);
		g_music_pid = -1;
	}
}

static pid_t g_sfx_pid = -1;
pid_t spawn_sfx(const char *path, float volume) // allows short noises can to overlap
{
	pid_t pid = fork();
	if (pid == 0)
	{
#if defined(__APPLE__)
		execlp(SFX_PLAYER, SFX_PLAYER, "-v", vol_arg(volume), path, (char *)NULL);

#elif defined(__linux__)
		execlp(SFX_PLAYER, SFX_PLAYER, path, (char *)NULL);
#endif
		_exit(1);
	}
	return pid; // >0 in parent, <0 on error
}

void play_sfx(const char *path, float volume, bool repeat_sound)
{
	if (!repeat_sound)
	{
		// clear finished cauldron sfx if any
		if (g_sfx_pid > 0)
		{
			int st;
			pid_t r = waitpid(g_sfx_pid, &st, WNOHANG);
			if (r != 0)
				g_sfx_pid = -1; // finished or error
		}
		// if still active, do not start another
		if (g_sfx_pid > 0)
			return;

		pid_t p = spawn_sfx(path, volume);
		if (p > 0)
			g_sfx_pid = p;
		return;
	}

	// allows overlaps
	(void)spawn_sfx(path, volume);
}

void stop_sfx(void)
{
	if (g_sfx_pid > 0)
	{
		kill(g_sfx_pid, SIGTERM);
		waitpid(g_sfx_pid, NULL, 0);
		g_sfx_pid = -1;
	}
}