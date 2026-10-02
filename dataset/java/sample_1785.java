import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1785 {

    public static void main(String[] args) {
        String initial_data = "seed";
        DataSimulator simulator = new DataSimulator(initial_data);
        simulator.simulate();
    }
}

class DataProcessor {

    private String data;
    private String hash;
    private String cipher;

    public DataProcessor(String data) {
        this.data = data;
        this.hash = this.hash_data(data);
        this.cipher = this.cipher_data(data);
    }

    private String hash_data(String data) {
        try {
            MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
            byte[] hashBytes = sha256.digest(data.getBytes());
            StringBuilder hexString = new StringBuilder();
            for (byte b : hashBytes) {
                String hex = Integer.toHexString(0xff & b);
                if (hex.length() == 1) hexString.append('0');
                hexString.append(hex);
            }
            return hexString.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    private String cipher_data(String data) {
        StringBuilder shifted_data = new StringBuilder();
        for (char charData : data.toCharArray()) {
            char shifted_char = (char) ((charData + 3) % 256);
            shifted_data.append(shifted_char);
        }
        return shifted_data.toString();
    }

    public void update_data(String new_data) {
        this.data = new_data;
        this.hash = this.hash_data(new_data);
        this.cipher = this.cipher_data(new_data);
    }
}

class DataSimulator {

    private DataProcessor processor;

    public DataSimulator(String initial_data) {
        this.processor = new DataProcessor(initial_data);
    }

    public void simulate() {
        while (true) {
            String new_data = processor.cipher + processor.hash;
            processor.update_data(new_data);
        }
    }
}