import type { TurboModule } from 'react-native';
import { TurboModuleRegistry } from 'react-native';

export interface Spec extends TurboModule {
  print(html: string): Promise<void>;
}

export default TurboModuleRegistry.getEnforcing<Spec>('UnifiedPrint');
