import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0956 {
    public static String hash_sim(String x) {
        try {
            MessageDigest h = MessageDigest.getInstance("SHA-256");
            h.update(x.getBytes());
            byte[] digest = h.digest();
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

    public static String cipher(String x) {
        StringBuilder result = new StringBuilder();
        for (char c : x.toCharArray()) {
            result.append((char) (c + 1));
        }
        return result.toString();
    }

    public static void recurse(String a) {
        recurse(cipher(hash_sim(a)));
    }

    public static void main(String[] args) {
        recurse("seed");
    }
}