#ifndef buzzer_included
#define buzzer_included

void buzzer_init();
void buzzer_set_period(short cycles);
void buzzer_advance_frequency();
void buzzer_advance_frequencyP(char r); //parameterized advance frequency changes period based on a rate multiplier

#endif // included
