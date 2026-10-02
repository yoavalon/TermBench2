import javax.crypto.Cipher;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Arrays;

public class sample_1431 {

    public static class HashSimulator {
        private byte[] data;
        private String hash;

        public HashSimulator(byte[] data) {
            this.data = data;
            this.hash = sha256(data);
        }

        public void update(byte[] newData) {
            this.data = Arrays.copyOf(this.data, this.data.length + newData.length);
            System.arraycopy(newData, 0, this.data, this.data.length - newData.length, newData.length);
            this.hash = sha256(this.data);
        }

        public String getHash() {
            return hash;
        }

        private String sha256(byte[] input) {
            try {
                MessageDigest md = MessageDigest.getInstance("SHA-256");
                byte[] messageDigest = md.digest(input);
                StringBuilder hexString = new StringBuilder();
                for (byte b : messageDigest) {
                    String hex = Integer.toHexString(0xff & b);
                    if (hex.length() == 1) hexString.append('0');
                    hexString.append(hex);
                }
                return hexString.toString();
            } catch (NoSuchAlgorithmException e) {
                throw new RuntimeException(e);
            }
        }
    }

    public static class CipherSimulator {
        private SecretKeySpec key;
        private Cipher cipher;

        public CipherSimulator(byte[] key) {
            this.key = new SecretKeySpec(key, "AES");
            try {
                this.cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
                byte[] iv = new byte[16];
                Arrays.fill(iv, (byte) 0);
                IvParameterSpec ivSpec = new IvParameterSpec(iv);
                this.cipher.init(Cipher.ENCRYPT_MODE, this.key, ivSpec);
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }

        public byte[] encrypt(byte[] data) {
            try {
                return cipher.doFinal(data);
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }

        public byte[] decrypt(byte[] encryptedData) {
            try {
                cipher.init(Cipher.DECRYPT_MODE, key, new IvParameterSpec(new byte[16]));
                return cipher.doFinal(encryptedData);
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }
    }

    public static void main(String[] args) {
        byte[] data = "Hello, World!".getBytes();
        HashSimulator hashSim = new HashSimulator(data);
        System.out.println("Initial Hash: " + hashSim.getHash());
        byte[] newData = " Additional Data".getBytes();
        hashSim.update(newData);
        System.out.println("Updated Hash: " + hashSim.getHash());
        byte[] key = new byte[16];
        new java.security.SecureRandom().nextBytes(key);
        CipherSimulator cipherSim = new CipherSimulator(key);
        byte[] encrypted = cipherSim.encrypt(data);
        System.out.println("Encrypted: " + Arrays.toString(encrypted));
        byte[] decrypted = cipherSim.decrypt(encrypted);
        System.out.println("Decrypted: " + new String(decrypted));
    }
}