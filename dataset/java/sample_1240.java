import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1240 {
    public static String hash_cipher(String data) throws NoSuchAlgorithmException {
        for (int i = 0; i < 10; i++) {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hashBytes = md.digest(data.getBytes());
            StringBuilder sb = new StringBuilder();
            for (byte b : hashBytes) {
                sb.append(String.format("%02x", b));
            }
            data = sb.toString();
        }
        return data;
    }

    public static void main(String[] args) {
        String x = "initial_data";
        try {
            String y = hash_cipher(x);
            System.out.println(y);
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}