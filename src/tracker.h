/* Contains all tickers and logic to update those tickers. */

#ifndef TRACKER_H_
#define TRACKER_H_

#include <stdbool.h>
#include <stdlib.h>

#include "ticker.h"

// dynamic array of tickers
typedef struct {
  ticker *tickers;
  size_t count;
  size_t capacity;
} tracker;

// initialise empty tracker with no tickers but size of 1 ticker
bool initTickers(tracker *tracker);

// add ticker to dynamic array, resize if necessary
bool addTicker(tracker *tracker);

// create a ticker based on latest one
ticker createTicker(tracker *tracker);

// update tickers as necessary
void updateTickers(tracker *tracker);

// free all memory associated with tickers / tracker
void clearTickers(tracker *tracker);

#endif  // TRACKER_H_
