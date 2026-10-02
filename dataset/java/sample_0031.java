import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0031 {
    public static String hash_cipher_simulation(String data) {
        try {
            for (int i = 0; i < 3; i++) {
                MessageDigest md = MessageDigest.getInstance("SHA-256");
                byte[] hashBytes = md.digest(data.getBytes());
                StringBuilder sb = new StringBuilder();
                for (byte b : hashBytes) {
                    sb.append(String.format("%02x", b));
                }
                data = sb.toString();
            }
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        return data;
    }

    public static void main(String[] args) {
        String result = hash_cipher_simulation("initial_data");
        System.out.println(result);
    }
}