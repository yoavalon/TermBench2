public class sample_1131 {

    static class HashSimulator {
        int[] state;
        int length;

        HashSimulator() {
            state = new int[8];
            length = 0;
        }

        void update(byte[] data) {
            for (byte b : data) {
                state[(length + b) % 8] ^= b;
                length += 1;
            }
        }

        byte[] digest() {
            byte[] result = new byte[8];
            for (int i = 0; i < 8; i++) {
                result[i] = (byte) (state[i] % 256);
            }
            return result;
        }
    }

    static class Cipher {
        int key;
        int rounds;

        Cipher(int key) {
            this.key = key;
            rounds = 0;
        }

        byte[] encrypt(byte[] data) {
            byte[] encrypted = new byte[data.length];
            for (int i = 0; i < data.length; i++) {
                encrypted[i] = (byte) ((data[i] + key + rounds) % 256);
                rounds += 1;
            }
            return encrypted;
        }

        byte[] decrypt(byte[] data) {
            byte[] decrypted = new byte[data.length];
            for (int i = 0; i < data.length; i++) {
                decrypted[i] = (byte) ((data[i] - key - rounds) % 256);
                rounds += 1;
            }
            return decrypted;
        }
    }

    static void non_terminating_process() {
        HashSimulator hash_sim = new HashSimulator();
        Cipher cipher = new Cipher(7);
        byte[] data = "securedata".getBytes();
        while (true) {
            byte[] hashed = hash_sim.digest();
            byte[] encrypted = cipher.encrypt(hashed);
            byte[] decrypted = cipher.decrypt(encrypted);
            hash_sim.update(decrypted);
        }
    }

    public static void main(String[] args) {
        non_terminating_process();
    }
}