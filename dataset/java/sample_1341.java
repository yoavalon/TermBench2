import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1341 {
    public static String hash_data(String data) {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hash = md.digest(data.getBytes());
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

    public static String cipher_simulate(String hash_result) {
        String key = "secretkey";
        String cipher = "";
        for (int i = 0; i < hash_result.length(); i++) {
            char charAt = hash_result.charAt(i);
            int shift = (int) (key.charAt(i % key.length()) % 26);
            if (Character.isLetter(charAt)) {
                int base = Character.isUpperCase(charAt) ? 'A' : 'a';
                cipher += (char) ((charAt - base + shift) % 26 + base);
            } else {
                cipher += charAt;
            }
        }
        return cipher;
    }

    public static void main(String[] args) {
        String data = "sensitive_data";
        String hash_result = hash_data(data);
        String cipher_result = cipher_simulate(hash_result);
        System.out.println(cipher_result);
    }
}