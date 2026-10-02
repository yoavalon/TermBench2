import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0058 {
    public static String boundary_conditions(byte[] data) {
        try {
            MessageDigest hash_object = MessageDigest.getInstance("SHA-256");
            hash_object.update(data);
            byte[] hash_digest = hash_object.digest();
            StringBuilder hexString = new StringBuilder();
            for (byte b : hash_digest) {
                String hex = Integer.toHexString(0xff & b);
                if(hex.length() == 1) hexString.append('0');
                hexString.append(hex);
            }
            return hexString.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args) {
        byte[] data = "hello_world".getBytes();
        String result = boundary_conditions(data);
        System.out.println(result);
    }
}