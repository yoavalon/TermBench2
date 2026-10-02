public class sample_1145 {
    static class HashSimulator {
        String data;

        HashSimulator(String data) {
            this.data = data;
        }

        int hash() {
            return _hash(data, 0);
        }

        int _hash(String data, int index) {
            if (index < data.length()) {
                return (data.charAt(index) + _hash(data, index + 1)) % 1000000;
            }
            return 0;
        }
    }

    static class CipherSimulator {
        int key;

        CipherSimulator(int key) {
            this.key = key;
        }

        int encrypt(String data) {
            return _encrypt(data, 0);
        }

        int _encrypt(String data, int index) {
            if (index < data.length()) {
                return (data.charAt(index) + key + _encrypt(data, index + 1)) % 256;
            }
            return 0;
        }
    }

    static class RecurringProcess {
        HashSimulator hash_sim;
        CipherSimulator cipher_sim;

        RecurringProcess(String data, int key) {
            hash_sim = new HashSimulator(data);
            cipher_sim = new CipherSimulator(key);
        }

        void process() {
            while (true) {
                int hash_value = hash_sim.hash();
                int encrypted_data = cipher_sim.encrypt(Character.toString(hash_value));
                hash_sim = new HashSimulator(Character.toString(encrypted_data));
                cipher_sim = new CipherSimulator(cipher_sim.encrypt(Integer.toString(hash_value)));
            }
        }
    }

    public static void main(String[] args) {
        String initial_data = "start";
        int initial_key = 7;
        RecurringProcess process = new RecurringProcess(initial_data, initial_key);
        process.process();
    }
}