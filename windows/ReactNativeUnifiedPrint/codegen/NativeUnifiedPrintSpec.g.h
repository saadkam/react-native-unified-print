
/*
 * This file is auto-generated from a NativeModule spec file in js.
 *
 * This is a C++ Spec class that should be used with MakeTurboModuleProvider to register native modules
 * in a way that also verifies at compile time that the native module matches the interface required
 * by the TurboModule JS spec.
 */
#pragma once
// clang-format off


#include <NativeModules.h>
#include <tuple>

namespace ReactNativeUnifiedPrintCodegen {

struct UnifiedPrintSpec : winrt::Microsoft::ReactNative::TurboModuleSpec {
  static constexpr auto methods = std::tuple{
      Method<void(std::string, Promise<void>) noexcept>{0, L"print"},
  };

  template <class TModule>
  static constexpr void ValidateModule() noexcept {
    constexpr auto methodCheckResults = CheckMethods<TModule, UnifiedPrintSpec>();

    REACT_SHOW_METHOD_SPEC_ERRORS(
          0,
          "print",
          "    REACT_METHOD(print) void print(std::string html, ::React::ReactPromise<void> &&result) noexcept { /* implementation */ }\n"
          "    REACT_METHOD(print) static void print(std::string html, ::React::ReactPromise<void> &&result) noexcept { /* implementation */ }\n");
  }
};

} // namespace ReactNativeUnifiedPrintCodegen
