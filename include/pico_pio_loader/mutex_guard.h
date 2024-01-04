#ifndef __PICO_PIO_LOADER_MUTEX_GUARD_H__
#define __PICO_PIO_LOADER_MUTEX_GUARD_H__

#include "pico/sync.h"

// RAII-style wrapper for mutex lock/unlock
class MutexGuard {
 public:
  MutexGuard(mutex_t* mutex) : mutex(mutex) {
    mutex_enter_blocking(mutex);
  }
  ~MutexGuard() {
    mutex_exit(mutex);
  }

private:
  mutex_t* mutex;
};

#endif
