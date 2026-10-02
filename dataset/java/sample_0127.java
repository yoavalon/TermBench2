import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0127 {
    public static String generate_hash(String data) throws NoSuchAlgorithmException {
        MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
        sha256.update(data.getBytes());
        byte[] hashBytes = sha256.digest();
        StringBuilder hexString = new StringBuilder();
        for (byte b : hashBytes) {
            String hex = Integer.toHexString(0xff & b);
            if (hex.length() == 1) hexString.append('0');
            hexString.append(hex);
        }
        return hexString.toString();
    }

    public static String simulate_cipher(String hash_val) {
        byte[] key = "secret".getBytes();
        StringBuilder cipher_text = new StringBuilder();
        for (int i = 0; i < hash_val.length(); i += 2) {
            byte byte_val = (byte) (Integer.parseInt(hash_val.substring(i, i + 2), 16) ^ key[i % key.length]);
            cipher_text.append(String.format("%02x", byte_val));
        }
        return cipher_text.toString();
    }

    public static void main(String[] args) {
        String data = "secure_message";
        try {
            String hash_val = generate_hash(data);
            String cipher_text = simulate_cipher(hash_val);
            System.out.println(cipher_text);
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}