//
// Created by Hanwei He on 2024/2/7.
//

#include "../include/time.h"

long timeval2millisecond(struct timeval time);

int get_time_gap(struct timeval start_time, struct timeval end_time) {
    return (int)(timeval2millisecond(end_time) - timeval2millisecond(start_time));
}


long timeval2millisecond(struct timeval time) {
    return time.tv_sec * 1000 + time.tv_usec / 1000;
}
