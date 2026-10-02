import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1892 {
    public static String simulate_hash(int x) {
        try {
            MessageDigest a = MessageDigest.getInstance("SHA-256");
            a.update(String.valueOf(x).getBytes());
            byte[] b = a.digest();
            StringBuilder sb = new StringBuilder();
            for (byte byte1 : b) {
                sb.append(String.format("%02x", byte1));
            }
            return sb.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args) {
        for (int i = 0; i < 10; i++) {
            System.out.println(simulate_hash(i));
        }
    }
}