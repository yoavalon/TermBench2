import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0015 {
    public static byte[] simulate_cipher(byte[] data, int iterations) throws NoSuchAlgorithmException {
        if (iterations <= 0) {
            return data;
        }
        for (int i = 0; i < iterations; i++) {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            data = md.digest(data);
        }
        return data;
    }

    public static void main(String[] args) {
        byte[] a = "initial_data".getBytes();
        int b = 3;
        try {
            byte[] result = simulate_cipher(a, b);
            System.out.println(java.util.Arrays.toString(result));
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}