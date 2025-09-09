#ifndef AUDIO_H
#define AUDIO_H
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

void audio_init(void);
void start_music(const char *path, float volume); // non-blocking, loops
void stop_music(void);
void play_sfx(const char *path, float volume, bool repeat_sound); // fire-and-forget
void stop_sfx(void);
#endif
