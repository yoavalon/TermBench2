import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0230 {
    public static String hashData(String data) {
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

    public static String encryptMessage(String message, String key) {
        StringBuilder encryptedMessage = new StringBuilder();
        for (int i = 0; i < message.length(); i++) {
            char charMessage = message.charAt(i);
            char charKey = key.charAt(i % key.length());
            char encryptedChar = (char) ((charMessage + charKey) % 256);
            encryptedMessage.append(encryptedChar);
        }
        return encryptedMessage.toString();
    }

    public static String decryptMessage(String encryptedMessage, String key) {
        StringBuilder decryptedMessage = new StringBuilder();
        for (int i = 0; i < encryptedMessage.length(); i++) {
            char charEncryptedMessage = encryptedMessage.charAt(i);
            char charKey = key.charAt(i % key.length());
            char decryptedChar = (char) ((charEncryptedMessage - charKey + 256) % 256);
            decryptedMessage.append(decryptedChar);
        }
        return decryptedMessage.toString();
    }

    public static void main(String[] args) {
        String originalData = "SecureCommunication";
        String key = "SecretKey123";
        String hashedData = hashData(originalData);
        String encryptedMessage = encryptMessage(originalData, key);
        String decryptedMessage = decryptMessage(encryptedMessage, key);
        System.out.println("Original Data: " + originalData);
        System.out.println("Hashed Data: " + hashedData);
        System.out.println("Encrypted Message: " + encryptedMessage);
        System.out.println("Decrypted Message: " + decryptedMessage);
    }
}