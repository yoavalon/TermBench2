import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.List;

public class sample_2492 {
    public static List<String> generate_hash_sequence(String seed, int length) {
        List<String> sequence = new ArrayList<>();
        for (int i = 0; i < length; i++) {
            try {
                MessageDigest hash_object = MessageDigest.getInstance("SHA-256");
                byte[] hashBytes = hash_object.digest(seed.getBytes());
                StringBuilder hexString = new StringBuilder();
                for (byte b : hashBytes) {
                    String hex = Integer.toHexString(0xff & b);
                    if (hex.length() == 1) hexString.append('0');
                    hexString.append(hex);
                }
                sequence.add(hexString.toString());
                seed = hexString.toString();
            } catch (NoSuchAlgorithmException e) {
                e.printStackTrace();
            }
        }
        return sequence;
    }

    public static void main(String[] args) {
        generate_hash_sequence("start", 10);
    }
}