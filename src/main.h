#pragma once

#ifndef MAIN_H
#define MAIN_H

#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <applibs/log.h>
#include <applibs/pwm.h>
#include <applibs/gpio.h>
#include <hw/avnet_mt3620_sk.h>

const struct timespec sleepTime = {0, 1e7L};

#endif
