public class sample_1125 {

    static class HashSimulator {
        String data;

        HashSimulator(String data) {
            this.data = data;
        }

        String hash_function(String value, int iterations) {
            if (iterations == 0) {
                return value;
            } else {
                return hash_function(cipher_function(value), iterations - 1);
            }
        }

        String cipher_function(String value) {
            int new_value = 0;
            for (char c : value.toCharArray()) {
                new_value += (int) c;
            }
            return String.valueOf(new_value);
        }
    }

    static class CipherSimulator {
        String data;

        CipherSimulator(String data) {
            this.data = data;
        }

        String cipher_function(String value) {
            StringBuilder new_value = new StringBuilder();
            for (char c : value.toCharArray()) {
                new_value.append((char) (c + 1));
            }
            return new_value.toString();
        }
    }

    static class RecursiveSimulator {
        String data;
        int iterations;

        RecursiveSimulator(String data, int iterations) {
            this.data = data;
            this.iterations = iterations;
        }

        void run_simulation() {
            HashSimulator hash_simulator = new HashSimulator(this.data);
            CipherSimulator cipher_simulator = new CipherSimulator(this.data);
            this.data = cipher_simulator.cipher_function(this.data);
            this.data = hash_simulator.hash_function(this.data, this.iterations);
            run_simulation();
        }
    }

    public static void main(String[] args) {
        String initial_data = "start";
        int iterations = 10;
        RecursiveSimulator simulator = new RecursiveSimulator(initial_data, iterations);
        simulator.run_simulation();
    }
}