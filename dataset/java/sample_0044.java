import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0044 {
    public static String hash_cipher(String data, int iterations) throws NoSuchAlgorithmException {
        MessageDigest hash_object = MessageDigest.getInstance("SHA-256");
        hash_object.update(data.getBytes());
        for (int i = 0; i < iterations; i++) {
            hash_object = MessageDigest.getInstance("SHA-256");
            hash_object.update(hash_object.digest());
        }
        return bytesToHex(hash_object.digest());
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
            String result = hash_cipher("test_data", 5);
            System.out.println(result);
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}