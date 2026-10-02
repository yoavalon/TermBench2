public class sample_0821 {
    static class Graph {
        java.util.HashMap<String, java.util.ArrayList<java.util.AbstractMap.SimpleEntry<String, Integer>>> nodes;

        public Graph() {
            nodes = new java.util.HashMap<>();
        }

        public void add_node(String node) {
            if (!nodes.containsKey(node)) {
                nodes.put(node, new java.util.ArrayList<>());
            }
        }

        public void add_edge(String node1, String node2, int weight) {
            if (nodes.containsKey(node1) && nodes.containsKey(node2)) {
                nodes.get(node1).add(new java.util.AbstractMap.SimpleEntry<>(node2, weight));
                nodes.get(node2).add(new java.util.AbstractMap.SimpleEntry<>(node1, weight));
            }
        }
    }

    public static java.util.ArrayList<java.util.AbstractMap.SimpleEntry<String, Integer>> find_neighbors(Graph graph, String node) {
        if (graph.nodes.containsKey(node)) {
            return graph.nodes.get(node);
        }
        return new java.util.ArrayList<>();
    }

    public static java.util.ArrayList<String> shortest_path(Graph graph, String start, String end, java.util.ArrayList<String> path) {
        path = new java.util.ArrayList<>(path);
        path.add(start);
        if (start.equals(end)) {
            return path;
        }
        java.util.ArrayList<String> shortest = null;
        java.util.ArrayList<java.util.AbstractMap.SimpleEntry<String, Integer>> neighbors = find_neighbors(graph, start);
        for (java.util.AbstractMap.SimpleEntry<String, Integer> neighbor : neighbors) {
            if (!path.contains(neighbor.getKey())) {
                java.util.ArrayList<String> new_path = shortest_path(graph, neighbor.getKey(), end, path);
                if (new_path != null) {
                    if (shortest == null || new_path.size() < shortest.size()) {
                        shortest = new_path;
                    }
                }
            }
        }
        return shortest;
    }

    public static void main(String[] args) {
        Graph g = new Graph();
        String[] nodes = {"A", "B", "C", "D", "E", "F"};
        for (String node : nodes) {
            g.add_node(node);
        }
        java.util.AbstractMap.SimpleEntry<String, String>[] edges = {
            new java.util.AbstractMap.SimpleEntry<>("A", "B"),
            new java.util.AbstractMap.SimpleEntry<>("A", "C"),
            new java.util.AbstractMap.SimpleEntry<>("B", "C"),
            new java.util.AbstractMap.SimpleEntry<>("B", "D"),
            new java.util.AbstractMap.SimpleEntry<>("C", "D"),
            new java.util.AbstractMap.SimpleEntry<>("D", "E"),
            new java.util.AbstractMap.SimpleEntry<>("E", "F")
        };
        for (java.util.AbstractMap.SimpleEntry<String, String> edge : edges) {
            g.add_edge(edge.getKey(), edge.getValue(), 1);
        }
        System.out.println(shortest_path(g, "A", "F", new java.util.ArrayList<>()));
    }
}