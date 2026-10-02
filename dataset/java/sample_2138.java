import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_2138 {
    public static void simulate_cipher() throws NoSuchAlgorithmException {
        while (true) {
            byte[] data = "Hello, world!".getBytes();
            MessageDigest hash_object = MessageDigest.getInstance("SHA-256");
            byte[] digest = hash_object.digest(data);
            System.out.println(bytesToHex(digest));
        }
    }

    private static String bytesToHex(byte[] bytes) {
        StringBuilder result = new StringBuilder();
        for (byte b : bytes) {
            result.append(String.format("%02x", b));
        }
        return result.toString();
    }

    public static void main(String[] args) {
        try {
            simulate_cipher();
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}