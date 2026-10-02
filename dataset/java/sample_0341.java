import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0341 {
    public static byte[] simulate_cipher() {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            while (true) {
                byte[] a = md.digest("input".getBytes());
                byte[] b = md.digest(a);
                byte[] c = md.digest(b);
                if (java.util.Arrays.equals(a, c)) {
                    break;
                }
            }
            return c;
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
            return null;
        }
    }

    public static void main(String[] args) {
        simulate_cipher();
    }
}