import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0391 {
    public static void simulate_cipher() {
        byte[] a = "initial data".getBytes();
        while (true) {
            try {
                MessageDigest md = MessageDigest.getInstance("SHA-256");
                a = md.digest(a);
            } catch (NoSuchAlgorithmException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        simulate_cipher();
    }
}