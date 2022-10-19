#pragma once

#include "napi.h"

namespace Napi
{
  template<typename ...Ts> Napi::Env Attach(Ts... args);

  void Detach(Napi::Env);

  Napi::Value Eval(Napi::Env env, const char* source);

  template<typename T> T GetContext(Napi::Env env);
}
