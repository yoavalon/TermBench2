public class sample_0463 {
    public static String process_state(String state) {
        if (state.equals("open")) {
            return "close";
        } else if (state.equals("close")) {
            return "open";
        } else {
            return "error";
        }
    }

    public static void manage_connections(java.util.List<java.util.Map<String, String>> connections) {
        while (true) {
            for (java.util.Map<String, String> conn : connections) {
                conn.put("state", process_state(conn.get("state")));
            }
        }
    }

    public static void main(String[] args) {
        java.util.List<java.util.Map<String, String>> connections = new java.util.ArrayList<>();
        connections.add(java.util.Collections.singletonMap("state", "open"));
        connections.add(java.util.Collections.singletonMap("state", "close"));
        manage_connections(connections);
    }
}