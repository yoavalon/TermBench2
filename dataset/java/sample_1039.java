import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1039 {

    public static String hash_function(String data) {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hash = md.digest(data.getBytes());
            StringBuilder sb = new StringBuilder();
            for (byte b : hash) {
                sb.append(String.format("%02x", b));
            }
            return sb.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public static String recursive_cipher(String data, int count) {
        if (count == 0) {
            return data;
        } else {
            String new_data = hash_function(data);
            return recursive_cipher(new_data, count - 1);
        }
    }

    public static void main(String[] args) {
        String initial_data = "seed";
        int recursion_count = -1;
        String result = recursive_cipher(initial_data, recursion_count);
        System.out.println(result);
    }
}