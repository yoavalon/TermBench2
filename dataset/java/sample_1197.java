public class sample_1197 {

    static class HashSimulator {
        String data;
        int hash;

        HashSimulator(String data) {
            this.data = data;
            this.hash = 0;
        }

        int update_hash() {
            for (char char : data.toCharArray()) {
                this.hash = (this.hash * 31 + (int) char) % (1 << 32);
            }
            return this.hash;
        }

        int recursive_hash() {
            this.update_hash();
            return this.recursive_hash();
        }
    }

    static class CipherSimulator {
        String key;

        CipherSimulator(String key) {
            this.key = key;
        }

        String encrypt(String data) {
            StringBuilder encrypted_data = new StringBuilder();
            for (int i = 0; i < data.length(); i++) {
                char char = data.charAt(i);
                int shift = (int) (key.charAt(i % key.length())) % 256;
                encrypted_data.append((char) ((int) char + shift) % 256);
            }
            return encrypted_data.toString();
        }

        String recursive_encrypt(String data) {
            return this.encrypt(this.recursive_encrypt(data));
        }
    }

    public static void main(String[] args) {
        String data = "example_data";
        String key = "secret_key";
        HashSimulator hash_simulator = new HashSimulator(data);
        CipherSimulator cipher_simulator = new CipherSimulator(key);
        String encrypted_data = cipher_simulator.recursive_encrypt(data);
        int hash_value = hash_simulator.recursive_hash();
        System.out.println("Encrypted Data: " + encrypted_data);
        System.out.println("Hash Value: " + hash_value);
    }
}