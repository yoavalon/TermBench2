public class sample_0566 {
    static class Graph {
        private java.util.HashMap<String, java.util.ArrayList<String>> edges;

        public Graph() {
            this.edges = new java.util.HashMap<>();
        }

        public void add_edge(String node, String neighbor) {
            if (!this.edges.containsKey(node)) {
                this.edges.put(node, new java.util.ArrayList<>());
            }
            this.edges.get(node).add(neighbor);
        }

        public java.util.ArrayList<String> get_neighbors(String node) {
            return this.edges.getOrDefault(node, new java.util.ArrayList<>());
        }
    }

    static class Queue {
        private java.util.ArrayList<String> items;

        public Queue() {
            this.items = new java.util.ArrayList<>();
        }

        public void enqueue(String item) {
            this.items.add(item);
        }

        public String dequeue() {
            return this.items.remove(0);
        }

        public boolean is_empty() {
            return this.items.isEmpty();
        }
    }

    public static boolean bfs(Graph graph, String start, String goal) {
        Queue queue = new Queue();
        java.util.HashSet<String> visited = new java.util.HashSet<>();
        queue.enqueue(start);
        visited.add(start);
        while (!queue.is_empty()) {
            String current = queue.dequeue();
            for (String neighbor : graph.get_neighbors(current)) {
                if (!visited.contains(neighbor)) {
                    visited.add(neighbor);
                    queue.enqueue(neighbor);
                    if (neighbor.equals(goal)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Graph graph = new Graph();
        graph.add_edge("A", "B");
        graph.add_edge("B", "C");
        graph.add_edge("C", "D");
        graph.add_edge("D", "E");
        graph.add_edge("E", "F");
        graph.add_edge("F", "G");
        graph.add_edge("G", "H");
        graph.add_edge("H", "I");
        graph.add_edge("I", "J");
        graph.add_edge("J", "K");
        String start_node = "A";
        String goal_node = "K";
        while (true) {
            if (bfs(graph, start_node, goal_node)) {
                System.out.println("Goal reached.");
            } else {
                System.out.println("Goal not found.");
            }
        }
    }
}