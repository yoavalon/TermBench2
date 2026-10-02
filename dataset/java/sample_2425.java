import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.List;

public class sample_2425 {

    public static List<String> simulate_cipher(int n) {
        int x = 0;
        List<String> result = new ArrayList<>();
        while (x < n) {
            try {
                MessageDigest hash_object = MessageDigest.getInstance("SHA-256");
                byte[] hash_bytes = hash_object.digest(String.valueOf(x).getBytes());
                StringBuilder hexString = new StringBuilder();
                for (byte b : hash_bytes) {
                    String hex = Integer.toHexString(0xff & b);
                    if (hex.length() == 1) hexString.append('0');
                    hexString.append(hex);
                }
                result.add(hexString.toString());
            } catch (NoSuchAlgorithmException e) {
                e.printStackTrace();
            }
            x += 1;
        }
        return result;
    }

    public static void main(String[] args) {
        simulate_cipher(10);
    }
}