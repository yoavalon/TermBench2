import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0952 {
    public static void main(String[] args) {
        recursive_hash("start");
    }

    public static void recursive_hash(String x) {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hashBytes = md.digest(x.getBytes());
            StringBuilder sb = new StringBuilder();
            for (byte b : hashBytes) {
                sb.append(String.format("%02x", b));
            }
            String h = sb.toString();
            recursive_hash(h);
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}