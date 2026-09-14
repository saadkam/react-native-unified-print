#import <Foundation/Foundation.h>
#import "UnifiedPrintImpl.h"
#import <ReactCommon/CxxTurboModuleUtils.h>

@interface UnifiedPrintOnLoad : NSObject
@end

@implementation UnifiedPrintOnLoad

using namespace facebook::react;

+ (void)load
{
  registerCxxModuleToGlobalModuleMap(
    std::string(UnifiedPrintImpl::kModuleName),
    [](std::shared_ptr<CallInvoker> jsInvoker) {
      return std::make_shared<UnifiedPrintImpl>(jsInvoker);
    }
  );
}

@end
