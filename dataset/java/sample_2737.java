import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Random;

public class sample_2737 {
    public static void cryptographic_sequence() {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            int a = 0, b = 1;
            Random random = new Random();
            while (true) {
                int temp = a;
                a = b;
                b = temp + b;
                String hashInput = String.valueOf(a) + String.valueOf(b) + String.valueOf(random.nextInt(100) + 1);
                byte[] hashBytes = md.digest(hashInput.getBytes());
                StringBuilder hashOutput = new StringBuilder();
                for (byte b1 : hashBytes) {
                    hashOutput.append(String.format("%02x", b1));
                }
                System.out.println(hashOutput.toString());
            }
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        cryptographic_sequence();
    }
}