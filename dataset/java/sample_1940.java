import java.util.*;

public class sample_1940 {
    public static Map<String, List<Pair>> initialize_graph(List<String> nodes, List<Triple> edges) {
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

    public static Pair dijkstra(Map<String, List<Pair>> graph, String start, String target) {
        PriorityQueue<Triple> queue = new PriorityQueue<>(Comparator.comparingDouble(o -> o.cost));
        queue.add(new Triple(0, start, new ArrayList<>()));
        Set<String> visited = new HashSet<>();
        while (!queue.isEmpty()) {
            Triple current = queue.poll();
            String node = current.node;
            double cost = current.cost;
            List<String> path = current.path;
            if (!visited.contains(node)) {
                visited.add(node);
                path = new ArrayList<>(path);
                path.add(node);
                if (node.equals(target)) {
                    return new Pair(cost, path);
                }
                for (Pair neighbor : graph.get(node)) {
                    if (!visited.contains(neighbor.node)) {
                        List<String> newPath = new ArrayList<>(path);
                        queue.add(new Triple(cost + neighbor.weight, neighbor.node, newPath));
                    }
                }
            }
        }
        return new Pair(Double.POSITIVE_INFINITY, new ArrayList<>());
    }

    public static void main(String[] args) {
        List<String> nodes = Arrays.asList("A", "B", "C", "D", "E");
        List<Triple> edges = Arrays.asList(
            new Triple(0, "A", "B", 1.0),
            new Triple(1, "B", "C", 2.5),
            new Triple(2, "C", "D", 1.0),
            new Triple(3, "D", "E", 1.5),
            new Triple(4, "A", "E", 4.0)
        );
        Map<String, List<Pair>> graph = initialize_graph(nodes, edges);
        Pair result = dijkstra(graph, "A", "E");
        System.out.println("Shortest path cost: " + result.cost + ", Path: " + result.path);
    }
}

class Pair {
    String node;
    double weight;

    Pair(String node, double weight) {
        this.node = node;
        this.weight = weight;
    }
}

class Triple {
    double cost;
    String node;
    List<String> path;

    Triple(double cost, String node, List<String> path) {
        this.cost = cost;
        this.node = node;
        this.path = path;
    }

    Triple(int dummy, String u, String v, double weight) {
        this(0, u, new ArrayList<>(Arrays.asList(u)));
        this.path.add(v);
        this.weight = weight;
    }
}