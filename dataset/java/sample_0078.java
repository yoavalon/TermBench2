import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0078 {
    public static String simulate_cipher(String data, int iterations) throws NoSuchAlgorithmException {
        MessageDigest hash_obj = MessageDigest.getInstance("SHA-256");
        hash_obj.update(data.getBytes());
        String digest = bytesToHex(hash_obj.digest());
        for (int i = 1; i < iterations; i++) {
            hash_obj.update(digest.getBytes());
            digest = bytesToHex(hash_obj.digest());
        }
        return digest;
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
            System.out.println(simulate_cipher("example data", 100));
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}