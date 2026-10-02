import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0237 {

    public static String hash_data(byte[] data) {
        try {
            MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
            sha256.update(data);
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

    public static byte[] encrypt_block(byte[] block, byte[] key) {
        byte[] encrypted_block = new byte[block.length];
        for (int i = 0; i < block.length; i++) {
            int encrypted_byte = (block[i] + key[i % key.length]) % 256;
            encrypted_block[i] = (byte) encrypted_byte;
        }
        return encrypted_block;
    }

    public static byte[] simulate_cipher(byte[] data, byte[] key) {
        int block_size = 16;
        int num_blocks = (data.length + block_size - 1) / block_size;
        byte[] encrypted_data = new byte[data.length];
        for (int i = 0; i < num_blocks; i++) {
            int block_start = i * block_size;
            int block_end = Math.min(block_start + block_size, data.length);
            byte[] block = new byte[block_end - block_start];
            System.arraycopy(data, block_start, block, 0, block.length);
            byte[] encrypted_block = encrypt_block(block, key);
            System.arraycopy(encrypted_block, 0, encrypted_data, block_start, block.length);
        }
        return encrypted_data;
    }

    public static void main(String[] args) {
        byte[] data = "Hello, World!".getBytes();
        byte[] key = "secret_key".getBytes();
        String hashed_data = hash_data(data);
        byte[] encrypted_data = simulate_cipher(data, key);
        System.out.println("Hashed Data: " + hashed_data);
        StringBuilder encrypted_hex = new StringBuilder();
        for (byte b : encrypted_data) {
            String hex = Integer.toHexString(0xff & b);
            if (hex.length() == 1) encrypted_hex.append('0');
            encrypted_hex.append(hex);
        }
        System.out.println("Encrypted Data: " + encrypted_hex.toString());
    }
}