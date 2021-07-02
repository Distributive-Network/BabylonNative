cmake_minimum_required(VERSION 3.12)

project(napi)

set(NAPI_JAVASCRIPT_ENGINE "v8")

set(SOURCES
    "include/napi/env.h"
    "include/napi/js_native_api.h"
    "include/napi/js_native_api_types.h"
    "include/napi/napi.h"
    "include/napi/napi-inl.h"
    "source/env.cc"
    "source/env_${NAPI_JAVASCRIPT_ENGINE}.cc"
    "source/js_native_api_${NAPI_JAVASCRIPT_ENGINE}.cc"
    "source/js_native_api_${NAPI_JAVASCRIPT_ENGINE}.h"
    "source/js_native_api_${NAPI_JAVASCRIPT_ENGINE}_internals.h")

add_library(napi ${SOURCES})

target_compile_definitions(napi PRIVATE NOMINMAX)
target_compile_definitions(napi PRIVATE _CRT_SECURE_NO_WARNINGS)

target_compile_definitions(napi PUBLIC NODE_ADDON_API_DISABLE_DEPRECATED)
target_compile_definitions(napi PUBLIC NODE_ADDON_API_DISABLE_NODE_SPECIFIC)

target_include_directories(napi PUBLIC "include")
