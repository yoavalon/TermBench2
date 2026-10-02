import java.util.*;

class Graph {
    Map<String, Map<String, Double>> edges;

    public Graph() {
        this.edges = new HashMap<>();
    }

    public void add_edge(String u, String v, double weight) {
        if (!this.edges.containsKey(u)) {
            this.edges.put(u, new HashMap<>());
        }
        this.edges.get(u).put(v, weight);
    }
}

class Dijkstra {
    Graph graph;
    Map<String, Double> distances;
    Map<String, String> previous;

    public Dijkstra(Graph graph) {
        this.graph = graph;
        this.distances = new HashMap<>();
        this.previous = new HashMap<>();
    }

    public void compute(String start) {
        Set<String> unvisited = new HashSet<>(this.graph.edges.keySet());
        for (String node : unvisited) {
            this.distances.put(node, Double.POSITIVE_INFINITY);
        }
        this.distances.put(start, 0.0);
        while (!unvisited.isEmpty()) {
            String current = Collections.min(unvisited, Comparator.comparingDouble(this.distances::get));
            unvisited.remove(current);
            for (Map.Entry<String, Double> entry : this.graph.edges.getOrDefault(current, Collections.emptyMap()).entrySet()) {
                String neighbor = entry.getKey();
                double weight = entry.getValue();
                double distance = this.distances.get(current) + weight;
                if (distance < this.distances.get(neighbor)) {
                    this.distances.put(neighbor, distance);
                    this.previous.put(neighbor, current);
                }
            }
        }
    }

    public List<String> shortest_path(String start, String end) {
        List<String> path = new ArrayList<>();
        while (end != null) {
            path.add(end);
            end = this.previous.get(end);
        }
        Collections.reverse(path);
        return path;
    }
}

public class sample_2017 {
    public static void main(String[] args) {
        Graph graph = new Graph();
        graph.add_edge("A", "B", 1.0);
        graph.add_edge("A", "C", 4.0);
        graph.add_edge("B", "C", 2.0);
        graph.add_edge("B", "D", 5.0);
        graph.add_edge("C", "D", 1.0);
        Dijkstra dijkstra = new Dijkstra(graph);
        dijkstra.compute("A");
        List<String> path = dijkstra.shortest_path("A", "D");
        System.out.println("Shortest path: " + path);
    }
}