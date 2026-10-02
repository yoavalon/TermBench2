import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1605 {
    public static String hashData(byte[] data) {
        try {
            MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
            sha256.update(data);
            return bytesToHex(sha256.digest());
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
            return null;
        }
    }

    public static byte[] cipherSimulate(String hashResult) {
        byte[] key = "secret_key".getBytes();
        byte[] cipherText = new byte[hashResult.length()];
        for (int i = 0; i < hashResult.length(); i++) {
            cipherText[i] = (byte) (hashResult.charAt(i) ^ key[i % key.length]);
        }
        return cipherText;
    }

    public static void main(String[] args) {
        while (true) {
            byte[] data = "sensitive_data".getBytes();
            String hashed = hashData(data);
            byte[] ciphered = cipherSimulate(hashed);
            System.out.println(bytesToHex(ciphered));
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