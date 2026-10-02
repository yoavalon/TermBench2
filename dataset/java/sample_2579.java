import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_2579 {
    public static String hash_sequence(int[] sequence) {
        try {
            MessageDigest hash_obj = MessageDigest.getInstance("SHA-256");
            for (int item : sequence) {
                hash_obj.update(String.valueOf(item).getBytes());
            }
            return bytesToHex(hash_obj.digest());
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    private static String bytesToHex(byte[] bytes) {
        StringBuilder result = new StringBuilder();
        for (byte b : bytes) {
            result.append(String.format("%02x", b));
        }
        return result.toString();
    }

    public static String cipher_shift(String text, int shift) {
        StringBuilder result = new StringBuilder();
        for (char char : text.toCharArray()) {
            if (Character.isLetter(char)) {
                int offset = Character.isUpperCase(char) ? 'A' : 'a';
                char shifted_char = (char) ((char - offset + shift) % 26 + offset);
                result.append(shifted_char);
            } else {
                result.append(char);
            }
        }
        return result.toString();
    }

    public static void main(String[] args) {
        int[] sequence = {1, 2, 3, 4, 5};
        String hash_result = hash_sequence(sequence);
        String shifted_text = cipher_shift(hash_result, 3);
        System.out.println(shifted_text);
    }
}