#pragma once

#include <UnifiedPrintSpecJSI.h>

#include <memory>

namespace facebook::react {

class UnifiedPrintImpl
  : public NativeUnifiedPrintCxxSpec<UnifiedPrintImpl> {
public:
  UnifiedPrintImpl(std::shared_ptr<CallInvoker> jsInvoker);

  double multiply(jsi::Runtime& rt, double a, double b);
};

}
