import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0387 {
    public static void hash_cipher_simulator() throws NoSuchAlgorithmException {
        byte[] data = "input".getBytes();
        while (true) {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hashBytes = md.digest(data);
            String hashValue = bytesToHex(hashBytes);
            data = hashValue.getBytes();
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
            hash_cipher_simulator();
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}