public class sample_0620 {
    public static String process_state(int state, String data) {
        if (state == 0) {
            return process_state(1, data + 'a');
        } else if (state == 1) {
            return process_state(2, data + 'b');
        } else if (state == 2) {
            return process_state(3, data + 'c');
        } else if (state == 3) {
            return data;
        }
        return ""; // Default return to satisfy the compiler
    }

    public static void main(String[] args) {
        String result = process_state(0, "");
        System.out.println(result);
    }
}