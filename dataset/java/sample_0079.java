import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0079 {
    public static void main(String[] args) {
        String data = "input_data";
        try {
            MessageDigest hash_object = MessageDigest.getInstance("SHA-256");
            hash_object.update(data.getBytes());
            byte[] digest = hash_object.digest();
            for (byte b : digest) {
                System.out.printf("%02x", b);
            }
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}