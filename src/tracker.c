#include <ncurses.h>
#include <stdbool.h>

#include "stringUtils.h"
#include "tracker.h"

bool initTickers(tracker *tracker) {
  tracker->tickers = (ticker *)malloc(1 * sizeof(ticker));

  if (tracker->tickers == NULL) {
    return false;
  }

  tracker->count = 0;
  tracker->capacity = 1;

  return true;
}

bool addTicker(tracker *tracker) {
  if (tracker->count == tracker->capacity) {
    tracker->capacity *= 2;
    tracker->tickers =
        (ticker *)realloc(tracker->tickers, tracker->capacity * sizeof(ticker));
    if (tracker->tickers == NULL) {
      return false;
    }
  }

  // TODO: code smelly, don't pass tracker in as an arg?
  tracker->tickers[tracker->count] = createTicker(tracker);
  tracker->count++;

  return true;
}

ticker createTicker(tracker *tracker) {
  if (tracker->count != 0) {
    int newTickerValue = tracker->tickers[tracker->count - 1].multiplier * 10;
    return (ticker){.name = getString(newTickerValue),
                    .multiplier = newTickerValue,
                    .factor = "",
                    .count = 0};
  }

  return (ticker){.name = "1", .multiplier = 1, .factor = "", .count = 0};
}

void updateTickers(tracker *tracker) {
  for (size_t i = 0; i < tracker->capacity; ++i) {
    tracker->tickers[i].count += (1 * tracker->tickers[i].multiplier);
  }
}

void clearTickers(tracker *tracker) {
  free(tracker->tickers);
  tracker->tickers = NULL;
  tracker->count = 0;
  tracker->capacity = 0;
}
