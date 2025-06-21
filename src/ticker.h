/* Ticker struct */

#ifndef TICKER_H_
#define TICKER_H_

typedef struct  {
    char* name;
    int multiplier;
    char* factor;  // for formatting e.g. e4 in 1e4
    unsigned int count;
} ticker;

#endif  // TICKER_H_
