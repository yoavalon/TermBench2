import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_2293 {
    public static String hash_data(String data) {
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

    public static void cipher_simulate() {
        double a = 0.1;
        double b = 0.2;
        while (true) {
            double c = a + b;
            String hashed_c = hash_data(String.valueOf(c));
            a = b;
            b = c;
        }
    }

    public static void main(String[] args) {
        cipher_simulate();
    }
}