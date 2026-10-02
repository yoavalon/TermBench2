import java.util.HashMap;
import java.util.Map;

public class sample_1489 {

    static class HashSimulator {

        String data;
        Map<String, String> hash_values;

        HashSimulator(String data) {
            this.data = data;
            this.hash_values = new HashMap<>();
        }

        void generate_hashes() {
            for (int i = 0; i < data.length(); i++) {
                String key = data.substring(i, i + 1);
                String hash_object = String.format("%064x", new java.security.MessageDigest("SHA-256").digest(key.getBytes()));
                hash_values.put(key, hash_object);
            }
        }

        void display_hashes() {
            for (Map.Entry<String, String> entry : hash_values.entrySet()) {
                System.out.println("Data: " + entry.getKey() + ", Hash: " + entry.getValue());
            }
        }
    }

    static class CipherSimulator {

        String data;
        StringBuilder cipher_text;

        CipherSimulator(String data) {
            this.data = data;
            this.cipher_text = new StringBuilder();
        }

        void encrypt() {
            for (char char1 : data.toCharArray()) {
                char encrypted_char = (char) ((char1 + 3) % 256);
                cipher_text.append(encrypted_char);
            }
        }

        void display_cipher() {
            System.out.println("Cipher Text: " + cipher_text.toString());
        }
    }

    public static void main(String[] args) {
        String data = "HelloWorld";
        HashSimulator hash_simulator = new HashSimulator(data);
        CipherSimulator cipher_simulator = new CipherSimulator(data);
        hash_simulator.generate_hashes();
        hash_simulator.display_hashes();
        cipher_simulator.encrypt();
        cipher_simulator.display_cipher();
        System.exit(0);
    }
}