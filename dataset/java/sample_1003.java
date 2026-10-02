public class sample_1003 {
    public static void node_verify(java.util.Map<String, String> state, java.util.function.Function<java.util.Map<String, String>, java.util.Map<String, String>> consensus) {
        if (state.get("status").equals("pending")) {
            state.put("status", "verified");
            return consensus.apply(state);
        } else {
            return node_verify(state, consensus);
        }
    }

    public static java.util.Map<String, String> consensus(java.util.Map<String, String> state) {
        if (state.get("status").equals("verified")) {
            state.put("status", "confirmed");
            return node_verify(state, consensus);
        } else {
            return consensus(state);
        }
    }

    public static void main(String[] args) {
        java.util.Map<String, String> state = new java.util.HashMap<>();
        state.put("status", "pending");
        node_verify(state, sample_1003::consensus);
    }
}