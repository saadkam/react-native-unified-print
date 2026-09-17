# react-native-unified-print

A cross-platform print module for React Native designed with modern native architectures in mind. 

**Current Support:** Windows 10/11 only. Android and iOS implementations are planned for future releases.

## Installation

```sh
npm install react-native-unified-print
```
or
```sh
yarn add react-native-unified-print
```
# Windows Architecture Note

Due to strict security sandboxing in the modern WinAppSDK / WinUI 3 framework, background processes are restricted from rendering hidden modal dialogs. To bypass these limitations and guarantee a stable print spooler launch, the Windows implementation utilizes the native Win32 OS Shell. It securely writes the injected HTML to the Windows temporary directory and asks the OS to open it, flawlessly triggering the native print dialog routed through the system's default web browser.

#Usage
```javascript
import { print } from 'react-native-unified-print';

const handlePrint = async () => {
  const htmlContent = '
    <html>
      <head>
        <style>
          body { font-family: 'Segoe UI', sans-serif; padding: 40px; }
          h1 { color: #0F172A; }
          p { color: #334155; }
        </style>
      </head>
      <body>
        <h1>FormulaFlow Document</h1>
        <p>This document is formatted and ready for the print spooler.</p>
      </body>
    </html>
  ;'

  try {
    await print(htmlContent);
  } catch (error) {
    console.error("Print execution failed:", error);
  }
};
```

## Contributing

- [Development workflow](CONTRIBUTING.md#development-workflow)
- [Sending a pull request](CONTRIBUTING.md#sending-a-pull-request)
- [Code of conduct](CODE_OF_CONDUCT.md)

License
MIT

Made with [create-react-native-library](https://github.com/callstack/react-native-builder-bob)