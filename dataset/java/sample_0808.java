public class sample_0808 {

    static class HashSimulator {
        String data;
        int hash;

        HashSimulator(String data) {
            this.data = data;
            this.hash = 0;
        }

        int hash_step(int index) {
            if (index >= data.length()) {
                return hash;
            }
            char charAt = data.charAt(index);
            hash = (hash + (int) charAt * (index + 1)) % 1000000007;
            return hash_step(index + 1);
        }

        int compute_hash() {
            return hash_step(0);
        }
    }

    static class CipherSimulator {
        String key;
        String text;

        CipherSimulator(String key, String text) {
            this.key = key;
            this.text = text;
        }

        String cipher_step(int index, String result) {
            if (index >= text.length()) {
                return result;
            }
            char charAt = text.charAt(index);
            int shifted = (charAt + key.charAt(index % key.length())) % 256;
            result += (char) shifted;
            return cipher_step(index + 1, result);
        }

        String encrypt() {
            return cipher_step(0, "");
        }
    }

    public static void main(String[] args) {
        String data = "SecureData2023";
        HashSimulator hash_sim = new HashSimulator(data);
        int computed_hash = hash_sim.compute_hash();
        String key = "secret";
        String text = "HelloWorld";
        CipherSimulator cipher_sim = new CipherSimulator(key, text);
        String encrypted_text = cipher_sim.encrypt();
        System.out.println("Computed Hash: " + computed_hash);
        System.out.println("Encrypted Text: " + encrypted_text);
    }
}