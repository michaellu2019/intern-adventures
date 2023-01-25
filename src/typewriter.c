#include <stdarg.h>
#include <unistd.h>
#include <ncurses.h>
#include <string.h>

#include "utils.h"
#include "typewriter.h"

bool is_sentence_punctuation(char c)
{
    return c == '.' || c == '!' || c == '?';
}

void wait_ms(long duration)
{
    usleep(duration * NANO_TO_MS);
}

void print(char *fmt, ...)
{
    printw(fmt);
    refresh();
}

void timed_ms_animated_print(uint32_t char_pause_ms, uint32_t sentence_pause_ms, char* fmt)
{
    for (int i = 0; i < strlen(fmt); i++)
    {
        addch(fmt[i]);
        refresh();
        if ((i == strlen(fmt) - 1 && !is_sentence_punctuation(fmt[i - 1])) || (is_sentence_punctuation(fmt[i]) && !is_sentence_punctuation(fmt[i + 1])))
        {
            wait_ms(sentence_pause_ms);
        } else 
        {
            wait_ms(char_pause_ms);
        }
    }
}

void timed_ms_animated_printf(uint32_t char_pause_ms, uint32_t sentence_pause_ms, char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int len = vsnprintf(NULL, 0, fmt, args);
    va_end(args);
    if (len < 0) return;

    char msg[len + 1];
    va_start(args, fmt);
    vsnprintf(msg, len + 1, fmt, args);
    va_end(args);

    timed_ms_animated_print(char_pause_ms, sentence_pause_ms, msg);
}

void animated_printf(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int len = vsnprintf(NULL, 0, fmt, args);
    va_end(args);
    if (len < 0) return;

    char msg[len + 1];
    va_start(args, fmt);
    vsnprintf(msg, len + 1, fmt, args);
    va_end(args);
    
    timed_ms_animated_print(STD_CHAR_PAUSE_MS, STD_SENTENCE_PAUSE_MS, msg);
}