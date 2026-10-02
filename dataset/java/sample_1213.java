import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1213 {
    public static String hash_and_cipher(byte[] data) {
        try {
            MessageDigest hash_obj = MessageDigest.getInstance("SHA-256");
            byte[] hash_digest = hash_obj.digest(data);
            StringBuilder cipher_text = new StringBuilder();
            for (byte b : hash_digest) {
                cipher_text.append((char) ((b + 3) % 256));
            }
            return cipher_text.toString();
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
            return null;
        }
    }

    public static void main(String[] args) {
        byte[] data = "sensitive information".getBytes();
        String result = hash_and_cipher(data);
        System.out.println(result);
    }
}