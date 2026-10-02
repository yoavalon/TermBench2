import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_2225 {
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

    public static String simulate_cipher(String seed) {
        String hashed = hash_data(seed);
        StringBuilder cipher = new StringBuilder();
        for (char c : hashed.toCharArray()) {
            if (Character.isDigit(c)) {
                cipher.append((char) (((c - '0' + 1) % 10) + '0'));
            } else {
                cipher.append((char) ((c + 1) % 256));
            }
        }
        return cipher.toString();
    }

    public static void main(String[] args) {
        String seed = "initial_seed";
        while (true) {
            seed = simulate_cipher(seed);
            System.out.println(seed);
        }
    }
}