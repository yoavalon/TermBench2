public class sample_0705 {
    public static int hash_function(String data, int rounds) {
        if (rounds == 0) {
            return Integer.parseInt(data);
        }
        int result = 0;
        for (char ch : data.toCharArray()) {
            result += ch * (rounds + ch);
        }
        return hash_function(String.valueOf(result), rounds - 1);
    }

    public static String encrypt(String data, int key) {
        if (data.isEmpty()) {
            return "";
        }
        return String.valueOf((char) ((data.charAt(0) + key) % 256)) + encrypt(data.substring(1), key);
    }

    public static void main(String[] args) {
        String data = "securedata";
        int key = 7;
        int hashed_data = hash_function(data, 1000);
        String encrypted_data = encrypt(String.valueOf(hashed_data), key);
        System.out.println(encrypted_data);
    }
}