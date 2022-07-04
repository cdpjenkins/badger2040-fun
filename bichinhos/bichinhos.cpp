#include "pico/stdlib.h"
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include "pico/time.h"
#include "pico/platform.h"

#include "common/pimoroni_common.hpp"
#include "badger2040.hpp"

#include "porquinho.h"
#include "gatinho.h"
#include "catiorinho.h"

using namespace pimoroni;

Badger2040 badger;

// uint32_t time() {
//   absolute_time_t t = get_absolute_time();
//   return to_ms_since_boot(t);
// }

int main() {

  stdio_init_all();

  sleep_ms(20);

  printf("\n\n=======\nbadger2040 starting up\n\n");

  badger.init();

  if(badger.pressed_to_wake(badger.A)) {
    printf("> A pressed\n");
    badger.image(porquinho);
    badger.pen(0);
    badger.text("Oink oink!", 55, 55, 0.6, 0);
  }

  else if(badger.pressed_to_wake(badger.B)) {
    printf("> B pressed\n");
    badger.image(gatinho);
    badger.pen(0);
    badger.text("MEOW!", 55, 55, 0.6, 0);

  }

  else if(badger.pressed_to_wake(badger.C)) {
    printf("> C pressed\n");
    badger.image(catiorinho);
    badger.pen(0);
    badger.text("Wrrf wrrrf!", 45, 55, 0.6, 0);

  }

  else {
    printf("> No A/B/C key pressed\n");
    badger.pen(15);
    badger.clear();

    badger.pen(0);
    badger.font("sans");
    badger.text("Press A, B, or C", 15, 65, 1.0f);
  }

  badger.update();
  while (badger.is_busy()) {
    sleep_ms(10);
  }
  badger.halt();

}
