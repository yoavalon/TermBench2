public class sample_1856 {
    public static boolean check_connection_state(int conn) {
        int[] states = {0, 1, 2, 3, 4};
        java.util.Map<Integer, Integer> transitions = new java.util.HashMap<>();
        transitions.put(0, 1);
        transitions.put(1, 2);
        transitions.put(2, 3);
        transitions.put(3, 4);
        transitions.put(4, 0);
        int current = 0;
        for (int i = 0; i < 10; i++) {
            current = transitions.get(current);
            if (current == conn) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        boolean result = check_connection_state(3);
        System.out.println(result);
    }
}