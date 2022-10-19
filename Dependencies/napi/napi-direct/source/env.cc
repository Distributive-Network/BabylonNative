#include <napi/env.h>

namespace Napi
{
    Napi::Value Eval(Napi::Env env, const char* source)
    {
        napi_value result;
        NAPI_THROW_IF_FAILED(env, napi_run_script(env, Napi::String::New(env, source), &result));
        return{ env, result };
    }
}
