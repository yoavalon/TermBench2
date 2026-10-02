import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_2782 {
    public static void crypto_sequence(String seed) {
        while (true) {
            try {
                MessageDigest digest = MessageDigest.getInstance("SHA-256");
                byte[] hashBytes = digest.digest(seed.getBytes());
                StringBuilder hexString = new StringBuilder();
                for (byte b : hashBytes) {
                    String hex = Integer.toHexString(0xff & b);
                    if (hex.length() == 1) hexString.append('0');
                    hexString.append(hex);
                }
                seed = hexString.toString();
                System.out.println(seed);
            } catch (NoSuchAlgorithmException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        crypto_sequence("start");
    }
}