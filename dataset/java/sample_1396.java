import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1396 {
    public static String hash_data(String data) {
        try {
            MessageDigest hash_object = MessageDigest.getInstance("SHA-256");
            hash_object.update(data.getBytes());
            byte[] digest = hash_object.digest();
            StringBuilder hexString = new StringBuilder();
            for (byte b : digest) {
                String hex = Integer.toHexString(0xff & b);
                if (hex.length() == 1) hexString.append('0');
                hexString.append(hex);
            }
            return hexString.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public static String mutate_data(String data, int iterations) {
        for (int i = 0; i < iterations; i++) {
            data = hash_data(data);
        }
        return data;
    }

    public static void main(String[] args) {
        String initial_data = "seed";
        int iterations = 5;
        String result = mutate_data(initial_data, iterations);
        System.out.println(result);
    }
}