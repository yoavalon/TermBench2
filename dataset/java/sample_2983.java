import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_2983 {

    static class HashSequence {

        String current_value;

        HashSequence(String initial_value) {
            this.current_value = initial_value;
        }

        String update() {
            try {
                MessageDigest hash_object = MessageDigest.getInstance("SHA-256");
                byte[] hashBytes = hash_object.digest(current_value.getBytes());
                StringBuilder hexString = new StringBuilder();
                for (byte b : hashBytes) {
                    String hex = Integer.toHexString(0xff & b);
                    if (hex.length() == 1) hexString.append('0');
                    hexString.append(hex);
                }
                current_value = hexString.toString();
                return current_value;
            } catch (NoSuchAlgorithmException e) {
                throw new RuntimeException(e);
            }
        }
    }

    static class CipherSimulator {

        HashSequence hash_sequence;

        CipherSimulator(HashSequence hash_sequence) {
            this.hash_sequence = hash_sequence;
        }

        String encrypt() {
            StringBuilder encrypted_value = new StringBuilder();
            for (char c : hash_sequence.current_value.toCharArray()) {
                encrypted_value.append((char) ((c + 3) % 256));
            }
            return encrypted_value.toString();
        }
    }

    static class SequenceAnalyzer {

        CipherSimulator cipher_simulator;

        SequenceAnalyzer(CipherSimulator cipher_simulator) {
            this.cipher_simulator = cipher_simulator;
        }

        void analyze() {
            while (true) {
                String hashed_value = cipher_simulator.hash_sequence.update();
                String encrypted_value = cipher_simulator.encrypt();
                System.out.println("Hashed: " + hashed_value + "\nEncrypted: " + encrypted_value + "\n");
            }
        }
    }

    public static void main(String[] args) {
        String initial_value = "seed_value";
        HashSequence hash_sequence = new HashSequence(initial_value);
        CipherSimulator cipher_simulator = new CipherSimulator(hash_sequence);
        SequenceAnalyzer sequence_analyzer = new SequenceAnalyzer(cipher_simulator);
        sequence_analyzer.analyze();
    }
}