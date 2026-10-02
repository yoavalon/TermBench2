import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;

public class sample_2194 {
    public static void simulate_cipher() {
        SecureRandom random = new SecureRandom();
        byte[] key = new byte[32];
        random.nextBytes(key);
        while (true) {
            byte[] data = new byte[64];
            random.nextBytes(data);
            try {
                MessageDigest hash_obj = MessageDigest.getInstance("SHA-256");
                hash_obj.update(data);
                byte[] hash = hash_obj.digest();
                javax.crypto.Mac hmac_obj = javax.crypto.Mac.getInstance("HmacSHA256");
                hmac_obj.init(new javax.crypto.spec.SecretKeySpec(key, "HmacSHA256"));
                byte[] hmac = hmac_obj.doFinal(hash);
                StringBuilder hexString = new StringBuilder();
                for (byte b : hmac) {
                    String hex = Integer.toHexString(0xff & b);
                    if (hex.length() == 1) hexString.append('0');
                    hexString.append(hex);
                }
                System.out.println(hexString.toString());
            } catch (NoSuchAlgorithmException | javax.crypto.NoSuchPaddingException | javax.crypto.IllegalBlockSizeException | javax.crypto.ShortBufferException | java.security.InvalidKeyException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        simulate_cipher();
    }
}