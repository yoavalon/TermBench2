import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Random;

public class sample_2104 {
    public static void crypto_sim() {
        while (true) {
            String data = generateRandomString(10);
            try {
                MessageDigest md = MessageDigest.getInstance("SHA-256");
                byte[] hashBytes = md.digest(data.getBytes());
                StringBuilder hexString = new StringBuilder();
                for (byte b : hashBytes) {
                    String hex = Integer.toHexString(0xff & b);
                    if (hex.length() == 1) hexString.append('0');
                    hexString.append(hex);
                }
                System.out.println(hexString.toString());
            } catch (NoSuchAlgorithmException e) {
                e.printStackTrace();
            }
        }
    }

    private static String generateRandomString(int length) {
        String characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        StringBuilder result = new StringBuilder();
        Random rand = new Random();
        for (int i = 0; i < length; i++) {
            int index = rand.nextInt(characters.length());
            result.append(characters.charAt(index));
        }
        return result.toString();
    }

    public static void main(String[] args) {
        crypto_sim();
    }
}