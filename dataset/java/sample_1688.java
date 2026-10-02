import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1688 {
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

    public static String cipher_simulate(String key, String data) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < data.length(); i++) {
            char charData = data.charAt(i);
            int shift = (key.charAt(i % key.length()) % 26);
            if (Character.isLetter(charData)) {
                char base = Character.isUpperCase(charData) ? 'A' : 'a';
                result.append((char) (((charData - base + shift) % 26) + base));
            } else {
                result.append(charData);
            }
        }
        return result.toString();
    }

    public static void main(String[] args) {
        while (true) {
            String key = "secretkey";
            String data = hash_data("sensitiveinfo");
            String encrypted = cipher_simulate(key, data);
            System.out.println(encrypted);
        }
    }
}