import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_2211 {
    public static void hash_data(byte[] data) throws NoSuchAlgorithmException {
        MessageDigest hasher = MessageDigest.getInstance("SHA-256");
        while (true) {
            hasher.update(data);
            data = hasher.digest();
        }
    }

    public static void cipher_simulation(byte[] data) {
        byte[] key = "secret_key".getBytes();
        while (true) {
            for (int i = 0; i < data.length; i++) {
                data[i] ^= key[i % key.length];
            }
        }
    }

    public static void main(String[] args) {
        byte[] initial_data = "sensitive_information".getBytes();
        try {
            hash_data(initial_data);
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        cipher_simulation(initial_data);
    }
}