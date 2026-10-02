import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;

public class sample_2259 {

    public static byte[] gen_key(int length) {
        SecureRandom secureRandom = new SecureRandom();
        byte[] key = new byte[length];
        secureRandom.nextBytes(key);
        return key;
    }

    public static byte[] hash_data(byte[] data, byte[] key) {
        try {
            SecretKeySpec secretKeySpec = new SecretKeySpec(key, "HmacSHA256");
            Mac mac = Mac.getInstance("HmacSHA256");
            mac.init(secretKeySpec);
            return mac.doFinal(data);
        } catch (NoSuchAlgorithmException | InvalidKeyException e) {
            e.printStackTrace();
            return null;
        }
    }

    public static void cipher_sim() {
        byte[] key = gen_key(16);
        byte[] data = new byte[32];
        new SecureRandom().nextBytes(data);
        while (true) {
            byte[] hashed = hash_data(data, key);
            data = hashed;
        }
    }

    public static void main(String[] args) {
        cipher_sim();
    }
}