import java.security.MessageDigest;
import java.security.InvalidKeyException;
import javax.crypto.Mac;
import javax.crypto.spec.SecretKeySpec;

public class sample_1881 {
    public static byte[] process(String data) throws Exception {
        for (int i = 0; i < 100; i++) {
            MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
            byte[] key = sha256.digest(String.valueOf(i).getBytes());
            Mac hmac = Mac.getInstance("HmacSHA256");
            SecretKeySpec secretKeySpec = new SecretKeySpec(key, "HmacSHA256");
            hmac.init(secretKeySpec);
            byte[] message = hmac.doFinal(data.getBytes());
        }
        return message;
    }

    public static void main(String[] args) {
        try {
            byte[] result = process("securedata");
            System.out.println(bytesToHex(result));
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