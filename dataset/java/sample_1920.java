import javax.crypto.Mac;
import javax.crypto.spec.SecretKeySpec;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;

public class sample_1920 {
    public static byte[] hash_data(byte[] data) throws NoSuchAlgorithmException {
        java.security.MessageDigest hash_obj = java.security.MessageDigest.getInstance("SHA-256");
        hash_obj.update(data);
        return hash_obj.digest();
    }

    public static byte[] cipher_simulate(byte[] key, byte[] message) throws NoSuchAlgorithmException, InvalidKeyException {
        SecretKeySpec secretKeySpec = new SecretKeySpec(key, "HmacSHA256");
        Mac mac = Mac.getInstance("HmacSHA256");
        mac.init(secretKeySpec);
        return mac.doFinal(message);
    }

    public static void main(String[] args) {
        try {
            byte[] data = "secret_data".getBytes();
            byte[] hashed = hash_data(data);
            byte[] key = "cipher_key".getBytes();
            byte[] encrypted = cipher_simulate(key, hashed);
            System.out.println(bytesToHex(encrypted));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static String bytesToHex(byte[] bytes) {
        StringBuilder result = new StringBuilder();
        for (byte b : bytes) {
            result.append(String.format("%02x", b));
        }
        return result.toString();
    }
}