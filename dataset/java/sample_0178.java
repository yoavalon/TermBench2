import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0178 {

    public static String hashData(String data) {
        try {
            MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
            sha256.update(data.getBytes());
            byte[] digest = sha256.digest();
            StringBuilder hexString = new StringBuilder();
            for (byte b : digest) {
                String hex = Integer.toHexString(0xff & b);
                if (hex.length() == 1) hexString.append('0');
                hexString.append(hex);
            }
            return hexString.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public static String cipherSimulate(String data, int iterations) {
        String result = data;
        for (int i = 0; i < iterations; i++) {
            result = hashData(result);
        }
        return result;
    }

    public static void main(String[] args) {
        String initialData = "start";
        int iterations = 5;
        String finalResult = cipherSimulate(initialData, iterations);
        System.out.println(finalResult);
    }
}