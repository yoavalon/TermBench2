import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0604 {
    public static String hash_cipher(String data, int depth) {
        if (depth == 0) {
            return data;
        } else {
            return hash_cipher(hash(data), depth - 1);
        }
    }

    public static String hash(String data) {
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

    public static void main(String[] args) {
        String result = hash_cipher("example_data", 3);
        System.out.println(result);
    }
}