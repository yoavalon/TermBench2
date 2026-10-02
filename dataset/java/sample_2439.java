import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_2439 {
    public static String crypto_simulator(String data) {
        try {
            for (int i = 0; i < 10; i++) {
                MessageDigest md = MessageDigest.getInstance("SHA-256");
                byte[] hashBytes = md.digest(data.getBytes());
                StringBuilder hexString = new StringBuilder();
                for (byte b : hashBytes) {
                    String hex = Integer.toHexString(0xff & b);
                    if (hex.length() == 1) hexString.append('0');
                    hexString.append(hex);
                }
                data = hexString.toString();
            }
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        return data;
    }

    public static void main(String[] args) {
        crypto_simulator("initial_data");
    }
}