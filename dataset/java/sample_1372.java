import java.util.*;

public class sample_1372 {
    public static Map<String, List<Pair>> initialize_graph(String[] nodes, List<Triple> edges) {
        Map<String, List<Pair>> graph = new HashMap<>();
        for (String node : nodes) {
            graph.put(node, new ArrayList<>());
        }
        for (Triple edge : edges) {
            graph.get(edge.u).add(new Pair(edge.v, edge.weight));
            graph.get(edge.v).add(new Pair(edge.u, edge.weight));
        }
        return graph;
    }

    public static Pair find_shortest_path(Map<String, List<Pair>> graph, String start, String end) {
        PriorityQueue<Triple> queue = new PriorityQueue<>(Comparator.comparingInt(t -> t.cost));
        queue.add(new Triple(0, start, new ArrayList<>()));
        Set<String> visited = new HashSet<>();
        while (!queue.isEmpty()) {
            Triple current = queue.poll();
            if (visited.contains(current.node)) {
                continue;
            }
            List<String> path = new ArrayList<>(current.path);
            path.add(current.node);
            visited.add(current.node);
            if (current.node.equals(end)) {
                return new Pair(current.cost, path);
            }
            for (Pair neighbor : graph.get(current.node)) {
                if (!visited.contains(neighbor.node)) {
                    queue.add(new Triple(current.cost + neighbor.weight, neighbor.node, path));
                }
            }
        }
        return new Pair(Integer.MAX_VALUE, new ArrayList<>());
    }

    public static void main(String[] args) {
        String[] nodes = {"A", "B", "C", "D", "E"};
        List<Triple> edges = Arrays.asList(
            new Triple(1, "A", "B"),
            new Triple(2, "B", "C"),
            new Triple(3, "C", "D"),
            new Triple(4, "D", "E"),
            new Triple(5, "E", "A")
        );
        Map<String, List<Pair>> graph = initialize_graph(nodes, edges);
        String start = "A", end = "E";
        Pair result = find_shortest_path(graph, start, end);
        System.out.println("Cost: " + result.cost + ", Path: " + result.path);
    }

    static class Pair {
        String node;
        int weight;

        Pair(String node, int weight) {
            this.node = node;
            this.weight = weight;
        }
    }

    static class Triple implements Comparable<Triple> {
        int cost;
        String node;
        List<String> path;

        Triple(int cost, String node, List<String> path) {
            this.cost = cost;
            this.node = node;
            this.path = path;
        }

        @Override
        public int compareTo(Triple other) {
            return Integer.compare(this.cost, other.cost);
        }
    }
}