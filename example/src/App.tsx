import { useState } from 'react';
import {
  View,
  Text,
  Button,
  StyleSheet,
  ActivityIndicator,
} from 'react-native';
import { print } from 'react-native-unified-print';

const SAMPLE_HTML = `
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8" />
    <title>Unified Print Test</title>
    <style>
      body {
        font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
        padding: 32px;
        color: #111;
      }
      h1 {
        color: #0078D4;
        border-bottom: 2px solid #0078D4;
        padding-bottom: 8px;
      }
      table {
        width: 100%;
        border-collapse: collapse;
        margin-top: 16px;
      }
      th, td {
        border: 1px solid #ccc;
        padding: 8px 12px;
        text-align: left;
      }
      th {
        background-color: #f3f3f3;
      }
      .footer {
        margin-top: 24px;
        font-size: 12px;
        color: #666;
      }
    </style>
  </head>
  <body>
    <h1>Unified Print Test Document</h1>
    <p>This document was rendered by <strong>React-Native-Unified-Print</strong></p>
    <table>
      <thead>
        <tr>
          <th>Item</th>
          <th>Platform</th>
          <th>Status</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <td>Print Engine</td>
          <td>WebView2 (CoreWebView2)</td>
          <td>Ready</td>
        </tr>
      </tbody>
    </table>
    <div class="footer">Generated via react-native-unified-print</div>
  </body>
</html>
`;

export default function App() {
  const [status, setStatus] = useState<string>('Idle');
  const [isPrinting, setIsPrinting] = useState<boolean>(false);

  const handlePrint = async () => {
    setIsPrinting(true);
    setStatus('Sending document to native print engine...');

    try {
      await print({ html: SAMPLE_HTML });
      setStatus('Print dialog opened successfully!');
    } catch (err: any) {
      setStatus(`Print failed: ${err?.message ?? err}`);
    } finally {
      setIsPrinting(false);
    }
  };

  return (
    <View style={styles.container}>
      <Text style={styles.title}>Unified Print</Text>
      <Text style={styles.status}>{status}</Text>

      {isPrinting && (
        <ActivityIndicator size="large" color="#0078D4" style={styles.loader} />
      )}

      <View style={styles.buttonContainer}>
        <Button
          title={isPrinting ? 'Opening Dialog...' : 'Test Print HTML'}
          onPress={handlePrint}
          disabled={isPrinting}
        />
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#1E1E2E',
    padding: 24,
  },
  title: {
    color: '#FFF',
    fontSize: 22,
    fontWeight: 'bold',
    marginBottom: 12,
  },
  status: {
    color: '#A6ADC8',
    fontSize: 14,
    marginBottom: 20,
    textAlign: 'center',
  },
  loader: {
    marginBottom: 16,
  },
  buttonContainer: {
    width: 220,
  },
});
