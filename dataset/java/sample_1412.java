import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.ArrayList;
import java.util.Collections;

class Graph {
    private Map<String, Map<String, Integer>> edges;

    public Graph() {
        this.edges = new HashMap<>();
    }

    public void add_edge(String node1, String node2, int weight) {
        if (!edges.containsKey(node1)) {
            edges.put(node1, new HashMap<>());
        }
        if (!edges.containsKey(node2)) {
            edges.put(node2, new HashMap<>());
        }
        edges.get(node1).put(node2, weight);
        edges.get(node2).put(node1, weight);
    }

    public Map<String, Integer> get_neighbors(String node) {
        return edges.getOrDefault(node, new HashMap<>());
    }
}

class Dijkstra {
    private Graph graph;

    public Dijkstra(Graph graph) {
        this.graph = graph;
    }

    public int find_shortest_path(String start, String end) {
        Map<String, Integer> distances = new HashMap<>();
        for (String node : graph.edges.keySet()) {
            distances.put(node, Integer.MAX_VALUE);
        }
        distances.put(start, 0);
        Set<String> unvisited = new HashSet<>(graph.edges.keySet());
        while (!unvisited.isEmpty()) {
            String current = Collections.min(unvisited, (a, b) -> distances.get(a) - distances.get(b));
            unvisited.remove(current);
            if (current.equals(end)) {
                break;
            }
            for (Map.Entry<String, Integer> entry : graph.get_neighbors(current).entrySet()) {
                String neighbor = entry.getKey();
                int weight = entry.getValue();
                int distance = distances.get(current) + weight;
                if (distance < distances.get(neighbor)) {
                    distances.put(neighbor, distance);
                }
            }
        }
        return distances.get(end);
    }
}

public class sample_1412 {
    public static void main(String[] args) {
        Graph g = new Graph();
        g.add_edge("A", "B", 1);
        g.add_edge("B", "C", 2);
        g.add_edge("C", "D", 3);
        g.add_edge("A", "D", 10);
        g.add_edge("B", "D", 4);
        Dijkstra dijkstra = new Dijkstra(g);
        int result = dijkstra.find_shortest_path("A", "D");
        System.out.println(result);
    }
}