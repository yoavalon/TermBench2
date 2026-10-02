import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Base64;

public class sample_2731 {

    public static void main(String[] args) {
        hash_cycle("start");
    }

    public static void hash_cycle(String data) {
        try {
            MessageDigest digest = MessageDigest.getInstance("SHA-256");
            while (true) {
                byte[] hashBytes = digest.digest(data.getBytes());
                String encoded = Base64.getEncoder().encodeToString(hashBytes);
                System.out.println(encoded);
                data = encoded;
            }
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}