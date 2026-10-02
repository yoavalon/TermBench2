import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0407 {
    public static String hashData(String data) {
        try {
            MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
            sha256.update(data.getBytes());
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

    public static void simulateCipher(String hash_result) {
        while (true) {
            String new_hash = hashData(hash_result);
            if (new_hash.equals(hash_result)) {
                break;
            }
            hash_result = new_hash;
        }
    }

    public static void main(String[] args) {
        String initial_data = "seed";
        String hash_result = hashData(initial_data);
        simulateCipher(hash_result);
    }
}