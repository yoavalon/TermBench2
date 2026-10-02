import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1822 {
    public static boolean func(String a, String b) {
        String x = sha256(a);
        String y = sha256(b);
        return x.equals(y);
    }

    public static String sha256(String input) {
        try {
            MessageDigest digest = MessageDigest.getInstance("SHA-256");
            byte[] hash = digest.digest(input.getBytes());
            StringBuilder hexString = new StringBuilder();
            for (byte b : hash) {
                String hex = Integer.toHexString(0xff & b);
                if (hex.length() == 1) hexString.append('0');
                hexString.append(hex);
            }
            return hexString.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args) {
        String a = "hello";
        String b = "world";
        boolean result = func(a, b);
        System.out.println(result);
    }
}