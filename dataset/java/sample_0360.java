import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0360 {
    public static void sim() {
        String a = "a";
        String b = "b";
        while (true) {
            a = sha256(a);
            b = sha256(b);
            if (a.equals(b)) {
                System.out.println("Match: " + a);
                break;
            }
        }
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
        sim();
    }
}