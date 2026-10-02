import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0120 {
    public static String hash_data(byte[] data) {
        try {
            MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
            sha256.update(data);
            byte[] digest = sha256.digest();
            StringBuilder hexString = new StringBuilder();
            for (byte b : digest) {
                String hex = Integer.toHexString(0xff & b);
                if(hex.length() == 1) hexString.append('0');
                hexString.append(hex);
            }
            return hexString.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public static byte[] simulate_cipher(byte[] data, byte[] key) {
        byte[] result = new byte[data.length];
        for (int i = 0; i < data.length; i++) {
            result[i] = (byte) (data[i] ^ key[i % key.length]);
        }
        return result;
    }

    public static void main(String[] args) {
        byte[] data = "SecretMessage".getBytes();
        byte[] key = "Key123".getBytes();
        String hashed = hash_data(data);
        byte[] encrypted = simulate_cipher(data, key);
        System.out.println(hashed);
        for (byte b : encrypted) {
            System.out.print((char) b);
        }
        System.out.println();
    }
}