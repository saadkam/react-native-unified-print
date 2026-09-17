#pragma once
#include "pch.h"
#include "NativeModules.h"

namespace ReactNativeUnifiedPrint {
  REACT_MODULE(UnifiedPrint);
  struct UnifiedPrint {
    REACT_INIT(Initialize);
    void Initialize(React::ReactContext const& reactContext) noexcept {
      m_context = reactContext;
    }

    REACT_METHOD(print);
    void print(std::string htmlContent, React::ReactPromise<void>&& promise) noexcept;

  private:
    React::ReactContext m_context;
  };
}
