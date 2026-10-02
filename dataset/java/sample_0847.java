public class sample_0847 {

    static class HashFunction {
        byte[] data;
        int hash_value;

        HashFunction(byte[] data) {
            this.data = data;
            this.hash_value = 0;
        }

        HashFunction update() {
            for (byte b : data) {
                this.hash_value = this.hash_value * 33 ^ b;
            }
            return this;
        }

        int digest() {
            return this.hash_value;
        }
    }

    static class CipherSimulator {
        byte[] key;
        byte[] data;
        byte[] encrypted_data;

        CipherSimulator(byte[] key, byte[] data) {
            this.key = key;
            this.data = data;
            this.encrypted_data = new byte[data.length];
        }

        CipherSimulator encrypt(int index) {
            if (index >= data.length) {
                return this;
            }
            encrypted_data[index] = (byte) (data[index] ^ key[index % key.length]);
            encrypt(index + 1);
            return this;
        }

        byte[] get_encrypted_data() {
            return this.encrypted_data;
        }
    }

    public static void main(String[] args) {
        byte[] original_data = "Hello, world!".getBytes();
        HashFunction hash_function = new HashFunction(original_data);
        hash_function.update();
        int hash_value = hash_function.digest();
        byte[] key = "secret".getBytes();
        CipherSimulator cipher_simulator = new CipherSimulator(key, original_data);
        cipher_simulator.encrypt(0);
        byte[] encrypted_data = cipher_simulator.get_encrypted_data();
        System.out.println("Hash Value: " + hash_value);
        System.out.print("Encrypted Data: ");
        for (byte b : encrypted_data) {
            System.out.print(b + " ");
        }
    }
}