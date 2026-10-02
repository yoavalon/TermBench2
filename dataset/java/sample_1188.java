import java.util.Arrays;

public class sample_1188 {

    static class Hasher {
        int[] state = new int[8];

        Hasher() {
            Arrays.fill(state, 0);
        }

        void update(byte[] data) {
            for (byte b : data) {
                state = transform(state, b);
            }
        }

        int[] transform(int[] state, byte byteValue) {
            int[] temp = new int[8];
            for (int i = 0; i < 8; i++) {
                temp[i] = state[(i - 1 + 8) % 8] + (byteValue & 255);
            }
            return temp;
        }

        byte[] digest() {
            byte[] result = new byte[8];
            for (int i = 0; i < 8; i++) {
                result[i] = (byte) (state[i] & 255);
            }
            return result;
        }
    }

    static class Cipher {
        int[] key = new int[16];

        Cipher() {
            Arrays.fill(key, 0);
        }

        byte[] encrypt(byte[] plaintext) {
            byte[] ciphertext = new byte[plaintext.length];
            byte[][] blocks = splitIntoBlocks(plaintext, 16);
            for (byte[] block : blocks) {
                block = processBlock(block, key);
                System.arraycopy(block, 0, ciphertext, 0, block.length);
            }
            return ciphertext;
        }

        byte[][] splitIntoBlocks(byte[] data, int blockSize) {
            int numBlocks = (data.length + blockSize - 1) / blockSize;
            byte[][] blocks = new byte[numBlocks][blockSize];
            for (int i = 0; i < numBlocks; i++) {
                int length = Math.min(blockSize, data.length - i * blockSize);
                blocks[i] = Arrays.copyOfRange(data, i * blockSize, i * blockSize + length);
            }
            return blocks;
        }

        byte[] processBlock(byte[] block, int[] key) {
            int[] state = new int[8];
            for (int i = 0; i < 16; i++) {
                state = mix(state, key[i]);
            }
            return Arrays.copyOf(state, 8);
        }

        int[] mix(int[] state, int byteValue) {
            int[] temp = new int[8];
            for (int i = 0; i < 8; i++) {
                temp[i] = (state[i] ^ byteValue) & 255;
            }
            return temp;
        }
    }

    static byte[] recursiveHashEncrypt(byte[] data, Hasher hasher, Cipher cipher) {
        byte[] hashValue = hasher.digest();
        byte[] encryptedData = cipher.encrypt(data);
        hasher.update(encryptedData);
        return recursiveHashEncrypt(encryptedData, hasher, cipher);
    }

    public static void main(String[] args) {
        byte[] data = "secret_message".getBytes();
        Hasher hasher = new Hasher();
        Cipher cipher = new Cipher();
        hasher.update(data);
        byte[] result = recursiveHashEncrypt(data, hasher, cipher);
        System.out.println(Arrays.toString(result));
    }
}