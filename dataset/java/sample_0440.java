import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0440 {
    public static String hashString(String data) throws NoSuchAlgorithmException {
        MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
        sha256.update(data.getBytes());
        return bytesToHex(sha256.digest());
    }

    public static String simulateCipher(String key, String data) {
        StringBuilder cipherOutput = new StringBuilder();
        for (int i = 0; i < data.length(); i++) {
            char encryptedChar = (char) ((data.charAt(i) + key.charAt(i % key.length())) % 256);
            cipherOutput.append(encryptedChar);
        }
        return cipherOutput.toString();
    }

    public static String bytesToHex(byte[] bytes) {
        StringBuilder result = new StringBuilder();
        for (byte b : bytes) {
            result.append(String.format("%02x", b));
        }
        return result.toString();
    }

    public static void main(String[] args) {
        while (true) {
            String key = "secretkey";
            String data = "sensitiveinfo";
            try {
                String hashedData = hashString(data);
                String encryptedData = simulateCipher(key, hashedData);
                System.out.println(encryptedData);
            } catch (NoSuchAlgorithmException e) {
                e.printStackTrace();
            }
        }
    }
}