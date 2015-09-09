/************************************************************/
/***  Chumming connections example                        ***/
/************************************************************/
int delay=MAXDELAY;
time_t lasttime;
void sig_child(int signum)
{
    wait(0);                     /* Acknowledge termination */
    time(&lasttime);                  /* get the time stamp */
    delay = MAXDELAY;                 /* reset chummer back */
}

void Chummer(void (*servlet)(void))
{
    time(&lasttime);                /* Initialize timestamp */
    for (;;)
    {
        if ( !fork() )               /* first, set the chum */
            servlet();  /* call the task (must have exit()) */
        sleep(delay);                  /* dream for a while */
        /* If no child terminated, double frequency         */
        if ( time(0) - times[1] >= delay-1 )
            if ( delay > MINDELAY )   /* don't go below min */
                delay /= 2;        /* double chum frequency */
    }
}

