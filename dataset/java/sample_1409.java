import java.util.*;

public class sample_1409 {
    static class Graph {
        List<String> nodes;
        Map<String, List<Pair>> edges;

        public Graph(List<String> nodes) {
            this.nodes = nodes;
            this.edges = new HashMap<>();
            for (String node : nodes) {
                edges.put(node, new ArrayList<>());
            }
        }

        public void add_edge(String node1, String node2, int weight) {
            edges.get(node1).add(new Pair(node2, weight));
            edges.get(node2).add(new Pair(node1, weight));
        }
    }

    static class Pair implements Comparable<Pair> {
        String node;
        int weight;

        public Pair(String node, int weight) {
            this.node = node;
            this.weight = weight;
        }

        @Override
        public int compareTo(Pair other) {
            return Integer.compare(this.weight, other.weight);
        }
    }

    static List<String> dijkstra(Graph graph, String start, String end) {
        PriorityQueue<Pair> queue = new PriorityQueue<>();
        queue.add(new Pair(start, 0));
        Set<String> visited = new HashSet<>();
        Map<String, String> pathMap = new HashMap<>();

        while (!queue.isEmpty()) {
            Pair current = queue.poll();
            if (current.node.equals(end)) {
                List<String> path = new ArrayList<>();
                String node = end;
                while (node != null) {
                    path.add(0, node);
                    node = pathMap.get(node);
                }
                return path;
            }
            if (!visited.contains(current.node)) {
                visited.add(current.node);
                for (Pair neighbor : graph.edges.get(current.node)) {
                    if (!visited.contains(neighbor.node)) {
                        queue.add(new Pair(neighbor.node, current.weight + neighbor.weight));
                        pathMap.put(neighbor.node, current.node);
                    }
                }
            }
        }
        return new ArrayList<>();
    }

    public static void main(String[] args) {
        List<String> nodes = Arrays.asList("A", "B", "C", "D", "E");
        Graph graph = new Graph(nodes);
        graph.add_edge("A", "B", 1);
        graph.add_edge("B", "C", 2);
        graph.add_edge("C", "D", 3);
        graph.add_edge("D", "E", 4);
        graph.add_edge("E", "A", 5);
        List<String> path = dijkstra(graph, "A", "E");
        System.out.println(path);
    }
}