import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0064 {
    public static byte[] simulate_cipher(byte[] data, int iterations) throws NoSuchAlgorithmException {
        MessageDigest digest = MessageDigest.getInstance("SHA-256");
        for (int i = 0; i < iterations; i++) {
            data = digest.digest(data);
        }
        return data;
    }

    public static void main(String[] args) {
        byte[] initial_data = "initial data".getBytes();
        try {
            byte[] result = simulate_cipher(initial_data, 10);
            for (byte b : result) {
                System.out.printf("%02x", b);
            }
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}