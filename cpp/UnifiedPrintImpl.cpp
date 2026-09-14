#include "UnifiedPrintImpl.h"

namespace facebook::react {

UnifiedPrintImpl::UnifiedPrintImpl(
  std::shared_ptr<CallInvoker> jsInvoker
)
  : NativeUnifiedPrintCxxSpec(std::move(jsInvoker)) {}

double UnifiedPrintImpl::multiply(
  jsi::Runtime& rt,
  double a,
  double b
) {
  return a * b;
}

}
