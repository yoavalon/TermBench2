import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0090 {
    public static String crypto_simulation(byte[] data) {
        try {
            MessageDigest hash_object = MessageDigest.getInstance("SHA-256");
            hash_object.update(data);
            byte[] hash_digest = hash_object.digest();
            StringBuilder hexString = new StringBuilder();
            for (byte b : hash_digest) {
                String hex = Integer.toHexString(0xff & b);
                if (hex.length() == 1) hexString.append('0');
                hexString.append(hex);
            }
            return hexString.substring(0, 10);
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
            return "";
        }
    }

    public static void main(String[] args) {
        byte[] data = "Sample data for hashing".getBytes();
        String result = crypto_simulation(data);
        System.out.println(result);
    }
}