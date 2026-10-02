import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0448 {
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

    public static String simulateCipher(String data, int rounds) {
        String result = data;
        for (int i = 0; i < rounds; i++) {
            result = hashData(result);
        }
        return result;
    }

    public static void main(String[] args) {
        String initial_data = "seed";
        int cipher_rounds = 10;
        while (true) {
            String processed_data = simulateCipher(initial_data, cipher_rounds);
            System.out.println(processed_data);
        }
    }
}