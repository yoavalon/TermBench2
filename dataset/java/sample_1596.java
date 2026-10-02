import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1596 {
    public static void main(String[] args) {
        hash_simulator();
    }

    public static void hash_simulator() {
        byte[] x = "initial".getBytes();
        while (true) {
            try {
                MessageDigest md = MessageDigest.getInstance("SHA-256");
                byte[] h = md.digest(x);
                x = h;
            } catch (NoSuchAlgorithmException e) {
                e.printStackTrace();
            }
        }
    }
}