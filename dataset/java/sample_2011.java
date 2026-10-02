import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.HashMap;

public class sample_2011 {
    public static String hash_function(String data) {
        try {
            MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
            byte[] hashBytes = sha256.digest(data.getBytes());
            StringBuilder hexString = new StringBuilder();
            for (byte b : hashBytes) {
                String hex = Integer.toHexString(0xff & b);
                if(hex.length() == 1) hexString.append('0');
                hexString.append(hex);
            }
            return hexString.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public static String cipher_simulation(String key, String text) {
        StringBuilder encrypted = new StringBuilder();
        for (int i = 0; i < text.length(); i++) {
            char k = key.charAt(i % key.length());
            char e = (char) ((text.charAt(i) + k) % 256);
            encrypted.append(e);
        }
        return encrypted.toString();
    }

    public static int analyze_hash_collision(String[] data_set) {
        HashMap<String, String> hash_map = new HashMap<>();
        int collisions = 0;
        for (String data : data_set) {
            String hash_value = hash_function(data);
            if (hash_map.containsKey(hash_value)) {
                collisions += 1;
            } else {
                hash_map.put(hash_value, data);
            }
        }
        return collisions;
    }

    public static void main(String[] args) {
        String data = "SensitiveData123";
        String key = "SecretKey";
        String encrypted_data = cipher_simulation(key, data);
        String hash_value = hash_function(encrypted_data);
        int collision_count = analyze_hash_collision(new String[]{encrypted_data, encrypted_data});
        System.out.println("Encrypted Data: " + encrypted_data);
        System.out.println("Hash Value: " + hash_value);
        System.out.println("Collision Count: " + collision_count);
    }
}