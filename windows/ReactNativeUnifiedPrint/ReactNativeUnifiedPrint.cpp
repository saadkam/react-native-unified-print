#include "pch.h"
#include "ReactNativeUnifiedPrint.h"
#include <winrt/Windows.Storage.h>
#include <winrt/Windows.System.h>

namespace ReactNativeUnifiedPrint {

  void UnifiedPrint::print(std::string htmlContent, React::ReactPromise<void>&& promise) noexcept {
    // 1. Resolve instantly to free the JS thread
    promise.Resolve();

    // 2. Inject the auto-print script so the OS dialog opens immediately
    std::string printableHtml = htmlContent + "\n<script>window.onload = function() { window.print(); }</script>";

    // 3. Execute the file operation safely in a background fire-and-forget task
    winrt::Windows::Foundation::IAsyncAction asyncOp = [](std::string html) -> winrt::Windows::Foundation::IAsyncAction {
      try {
        // Get the secure Windows Temp directory
        auto tempFolder = winrt::Windows::Storage::ApplicationData::Current().TemporaryFolder();

        // Create a temporary HTML file
        auto tempFile = co_await tempFolder.CreateFileAsync(
          L"UnifiedPrint_Document.html",
          winrt::Windows::Storage::CreationCollisionOption::ReplaceExisting
        );

        // Write the injected HTML to the disk
        co_await winrt::Windows::Storage::FileIO::WriteTextAsync(tempFile, winrt::to_hstring(html));

        // Ask the Win32 OS Shell to launch the file (opens default browser print dialog)
        co_await winrt::Windows::System::Launcher::LaunchFileAsync(tempFile);
      }
      catch (...) {
        // Fail silently in the background
      }
      }(printableHtml);
  }

} // namespace ReactNativeUnifiedPrint
