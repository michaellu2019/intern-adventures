#define STD_CHAR_PAUSE_MS 60
#define STD_SENTENCE_PAUSE_MS 1000

#define TITLE_INTERN "  _____ _   _ _______ ______ _____  _   _ \n |_   _| \\ | |__   __|  ____|  __ \\| \\ | |\n   | | |  \\| |  | |  | |__  | |__) |  \\| |\n   | | | . ` |  | |  |  __| |  _  /| . ` |\n  _| |_| |\\  |  | |  | |____| | \\ \\| |\\  |\n |_____|_| \\_|  |_|  |______|_|  \\_\\_| \\_|"
#define TITLE_ADVENTURES "           _______      ________ _   _ _______ _    _ _____  ______  _____ \n     /\\   |  __ \\ \\    / /  ____| \\ | |__   __| |  | |  __ \\|  ____|/ ____|\n    /  \\  | |  | \\ \\  / /| |__  |  \\| |  | |  | |  | | |__) | |__  | (___  \n   / /\\ \\ | |  | |\\ \\/ / |  __| | . ` |  | |  | |  | |  _  /|  __|  \\___ \\ \n  / ____ \\| |__| | \\  /  | |____| |\\  |  | |  | |__| | | \\ \\| |____ ____) |\n /_/    \\_\\_____/   \\/   |______|_| \\_|  |_|   \\____/|_|  \\_\\______|_____/ "

bool is_sentence_punctuation(char c);
void wait_ms(long duration);
void print(char *fmt, ...);
void timed_ms_animated_print(uint32_t char_pause_ms, uint32_t sentence_pause_ms, char* fmt);
void timed_ms_animated_printf(uint32_t char_pause_ms, uint32_t sentence_pause_ms, char* fmt, ...);
void animated_printf(char *fmt, ...);