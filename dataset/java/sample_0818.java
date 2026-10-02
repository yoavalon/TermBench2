import java.util.*;

public class sample_0818 {
    static class HashSimulator {
        String data;
        int digest;

        public HashSimulator(String data) {
            this.data = data;
            this.digest = hash_function(data);
        }

        public int hash_function(String data) {
            if (data.length() == 0) {
                return 0;
            } else {
                return (data.charAt(0) + hash_function(data.substring(1))) % 1000;
            }
        }

        public String encrypt(int key) {
            StringBuilder encrypted = new StringBuilder();
            for (char char1 : String.valueOf(digest).toCharArray()) {
                encrypted.append((char) ((char1 + key) % 256));
            }
            return encrypted.toString();
        }
    }

    static class CipherSimulator {
        int key;
        String data;

        public CipherSimulator(int key, String data) {
            this.key = key;
            this.data = data;
        }

        public String decrypt(String encrypted_data) {
            StringBuilder decrypted = new StringBuilder();
            for (char char1 : encrypted_data.toCharArray()) {
                decrypted.append((char) ((char1 - key) % 256));
            }
            return decrypted.toString();
        }
    }

    public static void main(String[] args) {
        String data = "SecureData";
        int key = 7;
        HashSimulator hash_sim = new HashSimulator(data);
        String encrypted = hash_sim.encrypt(key);
        CipherSimulator cipher_sim = new CipherSimulator(key, encrypted);
        String decrypted = cipher_sim.decrypt(encrypted);
        System.out.println("Original Data: " + data);
        System.out.println("Encrypted Data: " + encrypted);
        System.out.println("Decrypted Data: " + decrypted);
    }
}