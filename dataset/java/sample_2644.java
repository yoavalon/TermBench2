import java.util.*;

public class sample_2644 {
    static class Graph {
        List<String> nodes;
        Map<String, Map<String, Integer>> edges;

        Graph(List<String> nodes) {
            this.nodes = nodes;
            this.edges = new HashMap<>();
        }

        void add_edge(String u, String v, int weight) {
            if (!edges.containsKey(u)) {
                edges.put(u, new HashMap<>());
            }
            edges.get(u).put(v, weight);
        }

        Map<String, Integer> get_neighbors(String node) {
            return edges.getOrDefault(node, new HashMap<>());
        }
    }

    static class Dijkstra {
        Graph graph;
        String start;
        Map<String, Integer> distances;
        List<Map.Entry<String, Integer>> priority_queue;

        Dijkstra(Graph graph, String start) {
            this.graph = graph;
            this.start = start;
            this.distances = new HashMap<>();
            for (String node : graph.nodes) {
                distances.put(node, Integer.MAX_VALUE);
            }
            distances.put(start, 0);
            this.priority_queue = new ArrayList<>();
            priority_queue.add(new AbstractMap.SimpleEntry<>(0, start));
        }

        String extract_min() {
            int min_distance = Integer.MAX_VALUE;
            String min_node = null;
            for (Map.Entry<String, Integer> entry : priority_queue) {
                if (entry.getValue() < min_distance) {
                    min_distance = entry.getValue();
                    min_node = entry.getKey();
                }
            }
            priority_queue.removeIf(entry -> entry.getKey().equals(min_node));
            return min_node;
        }

        void update_distances(String current, Map<String, Integer> neighbors) {
            for (Map.Entry<String, Integer> entry : neighbors.entrySet()) {
                String neighbor = entry.getKey();
                int weight = entry.getValue();
                int new_distance = distances.get(current) + weight;
                if (new_distance < distances.get(neighbor)) {
                    distances.put(neighbor, new_distance);
                    priority_queue.add(new AbstractMap.SimpleEntry<>(new_distance, neighbor));
                }
            }
        }

        Map<String, Integer> run() {
            while (!priority_queue.isEmpty()) {
                String current = extract_min();
                Map<String, Integer> neighbors = graph.get_neighbors(current);
                update_distances(current, neighbors);
            }
            return distances;
        }
    }

    public static void main(String[] args) {
        List<String> nodes = Arrays.asList("A", "B", "C", "D", "E");
        Graph graph = new Graph(nodes);
        graph.add_edge("A", "B", 1);
        graph.add_edge("A", "C", 4);
        graph.add_edge("B", "C", 2);
        graph.add_edge("B", "D", 5);
        graph.add_edge("C", "D", 1);
        graph.add_edge("D", "E", 3);
        Dijkstra dijkstra = new Dijkstra(graph, "A");
        Map<String, Integer> shortest_paths = dijkstra.run();
        System.out.println(shortest_paths);
    }
}