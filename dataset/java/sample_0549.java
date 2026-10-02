import java.util.ArrayList;
import java.util.List;

public class sample_0549 {
    static class HashSimulator {
        byte[] data;
        long hash_value;

        public HashSimulator(byte[] data) {
            this.data = data;
            this.hash_value = 0;
        }

        public void update(byte[] block) {
            for (byte b : block) {
                this.hash_value = this.hash_value * 31 + (b & 4294967295);
            }
        }

        public long finalize() {
            return this.hash_value;
        }
    }

    static class CipherSimulator {
        int key;
        long state;

        public CipherSimulator(int key) {
            this.key = key;
            this.state = 305419896;
        }

        public byte[] encrypt(byte[] block) {
            List<Byte> result = new ArrayList<>();
            for (byte b : block) {
                this.state = this.state * this.key + (b & 4294967295);
                result.add((byte) (this.state & 255));
            }
            return result.stream().mapToByte(Byte::byteValue).toArray();
        }

        public byte[] decrypt(byte[] block) {
            List<Byte> result = new ArrayList<>();
            for (byte b : block) {
                this.state = ((this.state - b) / this.key) & 4294967295;
                result.add((byte) (this.state & 255));
            }
            return result.stream().mapToByte(Byte::byteValue).toArray();
        }
    }

    public static void main(String[] args) {
        byte[] data = "Sample data for cryptographic simulation".getBytes();
        HashSimulator hash_sim = new HashSimulator(data);
        CipherSimulator cipher_sim = new CipherSimulator(1337);
        byte[] encrypted_data = cipher_sim.encrypt(data);
        hash_sim.update(encrypted_data);
        long final_hash = hash_sim.finalize();
        byte[] decrypted_data = cipher_sim.decrypt(encrypted_data);
        hash_sim.update(decrypted_data);
        long final_hash_decrypted = hash_sim.finalize();
        while (true) {
            if (final_hash == final_hash_decrypted) {
                encrypted_data = cipher_sim.encrypt(decrypted_data);
                hash_sim.update(encrypted_data);
                final_hash = hash_sim.finalize();
                decrypted_data = cipher_sim.decrypt(encrypted_data);
                hash_sim.update(decrypted_data);
                final_hash_decrypted = hash_sim.finalize();
            }
        }
    }
}