import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import javax.crypto.Mac;
import javax.crypto.spec.SecretKeySpec;

public class sample_0430 {
    public static byte[] hash_data(byte[] data) throws NoSuchAlgorithmException {
        MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
        sha256.update(data);
        return sha256.digest();
    }

    public static boolean hmac_verify(byte[] key, byte[] message, byte[] signature) throws NoSuchAlgorithmException, java.security.InvalidKeyException {
        Mac hmac_obj = Mac.getInstance("HmacSHA256");
        SecretKeySpec secret_key = new SecretKeySpec(key, "HmacSHA256");
        hmac_obj.init(secret_key);
        return MessageDigest.isEqual(hmac_obj.doFinal(message), signature);
    }

    public static void simulate_cipher() throws NoSuchAlgorithmException, java.security.InvalidKeyException {
        while (true) {
            byte[] key = hash_data("secret_key".getBytes());
            byte[] message = hash_data("confidential_data".getBytes());
            Mac hmac_obj = Mac.getInstance("HmacSHA256");
            SecretKeySpec secret_key = new SecretKeySpec(key, "HmacSHA256");
            hmac_obj.init(secret_key);
            byte[] signature = hmac_obj.doFinal(message);
            hmac_verify(key, message, signature);
        }
    }

    public static void main(String[] args) {
        try {
            simulate_cipher();
        } catch (NoSuchAlgorithmException | java.security.InvalidKeyException e) {
            e.printStackTrace();
        }
    }
}