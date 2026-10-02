import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1988 {

    public static String hash_data(String data) {
        try {
            MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
            sha256.update(data.getBytes());
            return bytesToHex(sha256.digest());
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    private static String bytesToHex(byte[] bytes) {
        StringBuilder result = new StringBuilder();
        for (byte b : bytes) {
            result.append(String.format("%02x", b));
        }
        return result.toString();
    }

    public static String simulate_cipher(String hash_value) {
        StringBuilder result = new StringBuilder();
        for (char charValue : hash_value.toCharArray()) {
            if (Character.isDigit(charValue)) {
                result.append(String.valueOf((Character.getNumericValue(charValue) + 5) % 10));
            } else {
                result.append((char) ((charValue + 3) % 256));
            }
        }
        return result.toString();
    }

    public static void main(String[] args) {
        String data = "securedata";
        String hashed = hash_data(data);
        String ciphered = simulate_cipher(hashed);
        System.out.println(ciphered);
    }
}