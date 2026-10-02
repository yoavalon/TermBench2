import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.List;

public class sample_2576 {
    public static List<String> hashSequence(List<Object> data) throws NoSuchAlgorithmException {
        List<String> result = new ArrayList<>();
        for (Object item : data) {
            MessageDigest digest = MessageDigest.getInstance("SHA-256");
            byte[] hashBytes = digest.digest(String.valueOf(item).getBytes());
            StringBuilder hexString = new StringBuilder();
            for (byte b : hashBytes) {
                String hex = Integer.toHexString(0xff & b);
                if (hex.length() == 1) hexString.append('0');
                hexString.append(hex);
            }
            result.add(hexString.toString());
        }
        return result;
    }

    public static List<String> cipherSequence(List<String> data, int key) {
        List<String> result = new ArrayList<>();
        for (String item : data) {
            StringBuilder encryptedItem = new StringBuilder();
            for (char charItem : item.toCharArray()) {
                encryptedItem.append((char) ((charItem + key) % 256));
            }
            result.add(encryptedItem.toString());
        }
        return result;
    }

    public static void main(String[] args) {
        List<Object> data = List.of(1, 2, 3, 4, 5);
        int key = 5;
        try {
            List<String> hashedData = hashSequence(data);
            List<String> cipheredData = cipherSequence(hashedData, key);
            System.out.println(cipheredData);
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}