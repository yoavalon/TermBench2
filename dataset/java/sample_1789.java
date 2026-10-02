import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

class HashSimulator {

    private String data;
    private MessageDigest hasher;

    public HashSimulator(String data) throws NoSuchAlgorithmException {
        this.data = data;
        this.hasher = MessageDigest.getInstance("SHA-256");
        this.hasher.update(data.getBytes());
    }

    public void update(String additional_data) {
        this.hasher.update(additional_data.getBytes());
    }

    public String getHash() {
        byte[] hashBytes = this.hasher.digest();
        StringBuilder hexString = new StringBuilder();
        for (byte b : hashBytes) {
            String hex = Integer.toHexString(0xff & b);
            if(hex.length() == 1) hexString.append('0');
            hexString.append(hex);
        }
        return hexString.toString();
    }
}

class CipherSimulator {

    private String key;
    private int state;

    public CipherSimulator(String key) {
        this.key = key;
        this.state = 0;
    }

    public String encrypt(String plaintext) {
        StringBuilder ciphertext = new StringBuilder();
        for (char charPlaintext : plaintext.toCharArray()) {
            char shifted_char = (char) ((charPlaintext + key.charAt(state % key.length()) - 65) % 26 + 65);
            ciphertext.append(shifted_char);
            state += 1;
        }
        return ciphertext.toString();
    }

    public String decrypt(String ciphertext) {
        StringBuilder plaintext = new StringBuilder();
        for (char charCiphertext : ciphertext.toCharArray()) {
            char shifted_char = (char) ((charCiphertext - key.charAt(state % key.length()) - 65) % 26 + 65);
            plaintext.append(shifted_char);
            state += 1;
        }
        return plaintext.toString();
    }
}

public class sample_1789 {

    public static void main(String[] args) throws NoSuchAlgorithmException {
        HashSimulator hash_sim = new HashSimulator("initial_data");
        CipherSimulator cipher_sim = new CipherSimulator("key");
        while (true) {
            String data = "some_data";
            hash_sim.update(data);
            String hash_value = hash_sim.getHash();
            String encrypted_data = cipher_sim.encrypt(data);
            String decrypted_data = cipher_sim.decrypt(encrypted_data);
        }
    }
}