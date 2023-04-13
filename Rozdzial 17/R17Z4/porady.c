// mall.c -- use the Queue interface
// compile with queue.c
#include <stdio.h>
#include <stdlib.h> // for rand() and srand()
#include <time.h> // for time()
#include "kolejka.h" // change Item typedef
#define MIN_PER_HR 60.0

bool newcustomer(double x); // is there a new customer?
Item customertime(long when); // set customer parameters

int main(void)
{
    Queue line;
    Queue line2;
    Item temp; // new customer data
    Item temp2; // new customer data
    int hours; // hours of simulation
    int perhour; // average # of arrivals per hour
    long cycle, cyclelimit; // loop counter, limit
    long turnaways = 0; // turned away by full queue
    long customers = 0; // joined the queue
    long served = 0; // served during the simulation
    long served2 = 0; // served during the simulation
    long sum_line = 0; // cumulative line length
    long sum_line2 = 0; // cumulative line length
    int wait_time = 0; // time until Sigmund is free
    int wait_time2 = 0; // time until window 2 is free
    double min_per_cust; // average time between arrivals
    long line_wait = 0; // cumulative time in line
    long line_wait2 = 0; // cumulative time in line
    
    InitializeQueue(&line);
    InitializeQueue(&line2);
    srand((unsigned int) time(0)); // random initializing of rand()
    puts("Case Study: Sigmund Lander's Advice Booth");
    puts("Enter the number of simulation hours:");
    scanf("%d", &hours);
    cyclelimit = MIN_PER_HR * hours;
    puts("Enter the average number of customers per hour:");
    scanf("%d", &perhour);
    min_per_cust = MIN_PER_HR / perhour;

    for (cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (QueueIsFull(&line) && QueueIsFull(&line2))
                turnaways++;
            else
            {
                customers++;
                temp = customertime(cycle);
                // //metoda 1
                // EnQueue(temp, &line);
                // if (QueueIsFull(&line))
                //     EnQueue(temp, &line2);
                //metoda 2
                // int wynik = 0;
                // wynik = rand() % 2;
                // if (wynik == 0 && !QueueIsFull(&line))
                //     EnQueue(temp, &line);
                // else if (wynik == 0 && QueueIsFull(&line))
                //     EnQueue(temp, &line2);
                // else if (wynik == 1 && !QueueIsFull(&line2))
                //     EnQueue(temp, &line2);
                // else if (wynik == 1 && QueueIsFull(&line2))
                //     EnQueue(temp, &line);
                        
                // // {
                // //     if(!QueueIsFull(&line2))
                // //         EnQueue(temp, &line2);
                // //     else
                // //         EnQueue(temp, &line);
                // // }
                //metoda 3
                if (QueueItemCount(&line) < QueueItemCount(&line2))
                    EnQueue(temp, &line);
                else
                    EnQueue(temp, &line2);
    
            }
        }
        if (wait_time <= 0 && !QueueIsEmpty(&line))
        {
            DeQueue (&temp, &line);
            wait_time = temp.processtime;
            line_wait += cycle - temp.arrive;
            served++;
        }

        if (wait_time2 <= 0 && !QueueIsEmpty(&line2))
        {
            DeQueue (&temp, &line2);
            wait_time2 = temp.processtime;
            line_wait2 += cycle - temp.arrive;
            served2++;
        }

        if (wait_time > 0)
            wait_time--;
        if (wait_time2 > 0)
            wait_time2--;  
        sum_line += QueueItemCount(&line);
        sum_line2 += QueueItemCount(&line2);
    }
    if (customers > 0)
    {
        printf("customers accepted: %ld\n", customers);
        printf("customers served: %ld\n", served + served2);
        printf("turnaways: %ld\n", turnaways);
        printf("customers served queue 1: %ld\n", served);
        printf("customers served queue 2: %ld\n", served2);
        printf("average queue 1 size: %.2f\n", (double) sum_line / cyclelimit);
        printf("average queue 2 size: %.2f\n", (double) sum_line2 / cyclelimit);
        printf("average wait time for queue 1: %.2f minutes\n", (double) line_wait / served);
        printf("average wait time for queue 2: %.2f minutes\n", (double) line_wait2 / served2);
    }
    else
        puts("No customers!");

    EmptyTheQueue(&line);
    EmptyTheQueue(&line2);
    puts("Bye!");
    return 0;
}

// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x)
{
    if (rand() * x / RAND_MAX < 1)
        return true;
    else
        return false;
}

// when is the time at which the customer arrives
// function returns an Item structure with the arrival time
// set to when and the processing time set to a random value
// in the range 1 - 3
Item customertime(long when)
{
    Item cust;
    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;
    return cust;
}