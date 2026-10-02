public class sample_0872 {
    static class HashSimulator {
        int[] data;
        Integer result;

        HashSimulator(int[] data) {
            this.data = data;
            this.result = null;
        }

        void compute_hash() {
            if (data.length == 0) {
                result = 0;
            } else {
                result = _hash_recursive(data, 0);
            }
        }

        int _hash_recursive(int[] data, int index) {
            if (index == data.length) {
                return 0;
            } else {
                return (data[index] + _hash_recursive(data, index + 1)) % 1000000007;
            }
        }
    }

    static class CipherSimulator {
        int key;
        int[] data;
        Integer[] result;

        CipherSimulator(int key, int[] data) {
            this.key = key;
            this.data = data;
            this.result = null;
        }

        void encrypt() {
            if (data.length == 0) {
                result = new Integer[0];
            } else {
                result = _encrypt_recursive(data, 0);
            }
        }

        Integer[] _encrypt_recursive(int[] data, int index) {
            if (index == data.length) {
                return new Integer[0];
            } else {
                Integer[] rest = _encrypt_recursive(data, index + 1);
                Integer[] result = new Integer[rest.length + 1];
                result[0] = (data[index] + key) % 256;
                System.arraycopy(rest, 0, result, 1, rest.length);
                return result;
            }
        }
    }

    public static void main(String[] args) {
        int[] data = new int[]{'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
        HashSimulator hash_sim = new HashSimulator(data);
        hash_sim.compute_hash();
        System.out.println("Hash: " + hash_sim.result);
        int key = 42;
        CipherSimulator cipher_sim = new CipherSimulator(key, data);
        cipher_sim.encrypt();
        System.out.print("Encrypted: ");
        for (Integer value : cipher_sim.result) {
            System.out.print(value + " ");
        }
    }
}