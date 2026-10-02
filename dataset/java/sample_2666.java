public class sample_2666 {

    static class Sequence {
        int n;

        Sequence(int n) {
            this.n = n;
        }

        int[] generate() {
            int[] result = new int[n];
            for (int i = 0; i < n; i++) {
                result[i] = transform(i);
            }
            return result;
        }

        int transform(int x) {
            return (x * x + 3 * x + 1) % 101;
        }
    }

    static class HashSimulator {
        int[] sequence;

        HashSimulator(int[] sequence) {
            this.sequence = sequence;
        }

        int hash() {
            int total = 0;
            for (int num : sequence) {
                total = (total + num * 23) % 1001;
            }
            return total;
        }
    }

    static class CipherSimulator {
        int hash_value;

        CipherSimulator(int hash_value) {
            this.hash_value = hash_value;
        }

        int[] encrypt() {
            int[] encrypted = new int[hash_value];
            for (int i = 0; i < hash_value; i++) {
                encrypted[i] = (i * hash_value + i) % 1009;
            }
            return encrypted;
        }
    }

    public static void main(String[] args) {
        int n = 50;
        Sequence sequence = new Sequence(n);
        int[] generated = sequence.generate();
        HashSimulator hash_simulator = new HashSimulator(generated);
        int hash_value = hash_simulator.hash();
        CipherSimulator cipher_simulator = new CipherSimulator(hash_value);
        int[] encrypted = cipher_simulator.encrypt();
        for (int num : encrypted) {
            System.out.print(num + " ");
        }
    }
}