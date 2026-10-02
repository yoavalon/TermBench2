public class sample_0653 {
    public static int state_machine(int state, java.util.Stack<Integer> connections) {
        if (connections.isEmpty()) {
            return state;
        }
        int next_state = state ^ connections.pop();
        return state_machine(next_state, connections);
    }

    public static void main(String[] args) {
        int initial_state = 5;
        java.util.Stack<Integer> connections = new java.util.Stack<>();
        connections.push(4);
        connections.push(2);
        connections.push(1);
        int final_state = state_machine(initial_state, connections);
        System.out.println(final_state);
    }
}