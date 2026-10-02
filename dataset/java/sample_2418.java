import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_2418 {
    public static void main(String[] args) {
        String data = "hello";
        try {
            MessageDigest hash_object = MessageDigest.getInstance("SHA-256");
            byte[] hash_bytes = hash_object.digest(data.getBytes());
            StringBuilder hex_dig = new StringBuilder();
            for (byte b : hash_bytes) {
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