#include "main.h"

#define LED AVNET_MT3620_SK_PWM_CONTROLLER2

int res, led;
struct PwmState a = {2 * 1e4, 0, PWM_Polarity_Inversed, true};

void initAllChannels();
void breathe();
void closeAllChannels();

int main(void)
{
    led = PWM_Open(LED);
    initAllChannels();
    for (double i = 0; i < 1e2; i++)
        breathe();
    closeAllChannels();
    return 0;
}

void initAllChannels()
{
    for (unsigned int i = MT3620_PWM_CHANNEL0; i <= MT3620_PWM_CHANNEL2; i++)
        res = PWM_Apply(led, i, &a);
}

void breathe()
{
    for (unsigned int i = MT3620_PWM_CHANNEL0; i <= MT3620_PWM_CHANNEL2; i++)
    {
        for (a.dutyCycle_nsec = 0;
             a.dutyCycle_nsec < a.period_nsec;
             a.dutyCycle_nsec += 1e3)
        {
            res = PWM_Apply(led, i, &a);
            nanosleep(&sleepTime, NULL);
        }
        for (a.dutyCycle_nsec = 2 * 1e4;
             a.dutyCycle_nsec > 0;
             a.dutyCycle_nsec -= 1e3)
        {
            res = PWM_Apply(led, i, &a);
            nanosleep(&sleepTime, NULL);
        }
    }
}

void closeAllChannels()
{
    a.dutyCycle_nsec = 0;
    for (unsigned int i = MT3620_PWM_CHANNEL0; i <= MT3620_PWM_CHANNEL2; i++)
        res = PWM_Apply(led, i, &a);
}