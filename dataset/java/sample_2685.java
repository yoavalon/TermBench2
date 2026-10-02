import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.List;

public class sample_2685 {

    static class HashSimulator {
        private String data;
        private List<String> hash_values;

        public HashSimulator(String data) {
            this.data = data;
            this.hash_values = new ArrayList<>();
        }

        public void generate_hashes(int rounds) {
            for (int i = 0; i < rounds; i++) {
                try {
                    MessageDigest md = MessageDigest.getInstance("SHA-256");
                    byte[] hash = md.digest(data.getBytes());
                    StringBuilder hexString = new StringBuilder();
                    for (byte b : hash) {
                        String hex = Integer.toHexString(0xff & b);
                        if (hex.length() == 1) hexString.append('0');
                        hexString.append(hex);
                    }
                    data = hexString.toString();
                    hash_values.add(data);
                } catch (NoSuchAlgorithmException e) {
                    e.printStackTrace();
                }
            }
        }

        public List<String> get_hash_sequence() {
            return hash_values;
        }
    }

    static class CipherSimulator {
        private String key;
        private List<String> encrypted_values;

        public CipherSimulator(String key) {
            this.key = key;
            this.encrypted_values = new ArrayList<>();
        }

        public void encrypt(String value) {
            StringBuilder encrypted_value = new StringBuilder();
            for (int i = 0; i < value.length(); i++) {
                char c = (char) ((value.charAt(i) + key.charAt(i % key.length())) % 256);
                encrypted_value.append(c);
            }
            encrypted_values.add(encrypted_value.toString());
        }

        public List<String> get_encrypted_sequence() {
            return encrypted_values;
        }
    }

    public static void main(String[] args) {
        String initial_data = "seed";
        int hash_rounds = 5;
        String cipher_key = "key";
        HashSimulator hash_sim = new HashSimulator(initial_data);
        hash_sim.generate_hashes(hash_rounds);
        List<String> hash_sequence = hash_sim.get_hash_sequence();
        CipherSimulator cipher_sim = new CipherSimulator(cipher_key);
        for (String hash_value : hash_sequence) {
            cipher_sim.encrypt(hash_value);
        }
        List<String> encrypted_sequence = cipher_sim.get_encrypted_sequence();
        System.out.println(encrypted_sequence);
    }
}