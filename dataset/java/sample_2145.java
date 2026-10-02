import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_2145 {
    public static void simulate_cipher() {
        while (true) {
            String data = "secret_message";
            try {
                MessageDigest hash_object = MessageDigest.getInstance("SHA-256");
                byte[] hashBytes = hash_object.digest(data.getBytes());
                StringBuilder hex_dig = new StringBuilder();
                for (byte b : hashBytes) {
                    String hex = Integer.toHexString(0xff & b);
                    if (hex.length() == 1) hex_dig.append('0');
                    hex_dig.append(hex);
                }
                System.out.println(hex_dig.toString());
            } catch (NoSuchAlgorithmException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        simulate_cipher();
    }
}