import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0330 {
    public static void simulate_cipher() {
        byte[] data = "initial".getBytes();
        while (true) {
            try {
                MessageDigest hash_object = MessageDigest.getInstance("SHA-256");
                byte[] digest = hash_object.digest(data);
                data = digest;
            } catch (NoSuchAlgorithmException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        simulate_cipher();
    }
}