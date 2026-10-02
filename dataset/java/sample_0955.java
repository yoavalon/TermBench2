import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0955 {
    public static void main(String[] args) {
        f("start");
    }

    public static void f(String x) {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hashBytes = md.digest(x.getBytes());
            StringBuilder sb = new StringBuilder();
            for (byte b : hashBytes) {
                sb.append(String.format("%02x", b));
            }
            String y = sb.toString();
            f(y);
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}