import { NativeModules } from 'react-native';

const { UnifiedPrint } = NativeModules;

export interface PrintOptions {
  html: string;
}

export function print(options: PrintOptions): Promise<void> {
  if (!UnifiedPrint) {
    return Promise.reject(
      new Error(
        'UnifiedPrint native module is not linked. Make sure react-native-unified-print is autolinked.'
      )
    );
  }

  if (!options?.html) {
    return Promise.reject(new Error('HTML content must not be empty.'));
  }

  return UnifiedPrint.print(options.html);
}
