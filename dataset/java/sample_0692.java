public class sample_0692 {
    public static String check_connection(String state, int attempts) {
        if (attempts == 0) {
            return "Disconnected";
        } else if (state.equals("Connected")) {
            return "Connected";
        } else {
            return check_connection(attempts % 2 == 0 ? "Connected" : "Disconnected", attempts - 1);
        }
    }

    public static void main(String[] args) {
        check_connection("Disconnected", 5);
    }
}