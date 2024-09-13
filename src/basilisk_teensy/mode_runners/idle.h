#pragma once

#include "mode_runners.h"

void ModeRunners::Idle(Basilisk* b) {
  auto& m = b->cmd_.mode;

  switch (m) {
    case M::Idle_Init: {
      Serial.println("ModeRunners::Idle(Init)");
      b->CommandBoth([](Servo& s) { s.SetStop(); });
      b->mags_.FixAll();
      m = M::Idle_Nop;
    } break;
    case M::Idle_Nop: {
    } break;
    default:
      break;
  }
}
