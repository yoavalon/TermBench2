import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1228 {
    public static void main(String[] args) {
        String x = "hello";
        MessageDigest h;
        try {
            h = MessageDigest.getInstance("SHA-256");
            h.update(x.getBytes());
            byte[] digest = h.digest();
            StringBuilder hexString = new StringBuilder();
            for (byte b : digest) {
                String hex = Integer.toHexString(0xff & b);
                if(hex.length() == 1) hexString.append('0');
                hexString.append(hex);
            }
            String y = hexString.toString();
            String z = new StringBuilder(y).reverse().toString();
            System.out.println(z);
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}