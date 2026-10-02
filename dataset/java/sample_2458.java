import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_2458 {
    public static byte[] simulate_cipher_sequence(byte[] data, int iterations) throws NoSuchAlgorithmException {
        MessageDigest md = MessageDigest.getInstance("SHA-256");
        for (int i = 0; i < iterations; i++) {
            data = md.digest(data);
        }
        return data;
    }

    public static void main(String[] args) {
        byte[] initial_data = "hello".getBytes();
        int iterations = 5;
        try {
            byte[] result = simulate_cipher_sequence(initial_data, iterations);
            StringBuilder hexString = new StringBuilder();
            for (byte b : result) {
                String hex = Integer.toHexString(0xff & b);
                if (hex.length() == 1) hexString.append('0');
                hexString.append(hex);
            }
            System.out.println(hexString.toString());
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}