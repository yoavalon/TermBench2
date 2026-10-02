import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0893 {

    static class HashSimulator {
        String data;
        int depth;
        int current_depth;

        HashSimulator(String data, int depth) {
            this.data = data;
            this.depth = depth;
            this.current_depth = 0;
        }

        String hash_data() {
            try {
                MessageDigest md = MessageDigest.getInstance("SHA-256");
                byte[] hashBytes = md.digest(data.getBytes());
                StringBuilder sb = new StringBuilder();
                for (byte b : hashBytes) {
                    sb.append(String.format("%02x", b));
                }
                return sb.toString();
            } catch (NoSuchAlgorithmException e) {
                throw new RuntimeException(e);
            }
        }

        String recursive_hash() {
            if (current_depth >= depth) {
                return hash_data();
            } else {
                current_depth += 1;
                data = hash_data();
                return recursive_hash();
            }
        }
    }

    static class CipherSimulator {
        String key;
        int rounds;
        int current_round;

        CipherSimulator(String key, int rounds) {
            this.key = key;
            this.rounds = rounds;
            this.current_round = 0;
        }

        String simple_cipher(String data) {
            StringBuilder result = new StringBuilder();
            for (char char1 : data.toCharArray()) {
                result.append((char) ((char1 + key.charAt(0)) % 256));
            }
            return result.toString();
        }

        String recursive_cipher(String data) {
            if (current_round >= rounds) {
                return data;
            } else {
                current_round += 1;
                data = simple_cipher(data);
                return recursive_cipher(data);
            }
        }
    }

    public static void main(String[] args) {
        String initial_data = "SecureData";
        int hash_depth = 5;
        int cipher_rounds = 3;
        String key = "Secret";
        HashSimulator hash_simulator = new HashSimulator(initial_data, hash_depth);
        String hashed_data = hash_simulator.recursive_hash();
        CipherSimulator cipher_simulator = new CipherSimulator(key, cipher_rounds);
        String encrypted_data = cipher_simulator.recursive_cipher(hashed_data);
        System.out.println(encrypted_data);
    }
}