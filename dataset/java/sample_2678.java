import java.util.*;

public class sample_2678 {

    static class Graph {
        Map<String, List<Pair>> adj_list;

        public Graph() {
            adj_list = new HashMap<>();
        }

        public void add_vertex(String vertex) {
            if (!adj_list.containsKey(vertex)) {
                adj_list.put(vertex, new ArrayList<>());
            }
        }

        public void add_edge(String vertex1, String vertex2, int weight) {
            if (adj_list.containsKey(vertex1) && adj_list.containsKey(vertex2)) {
                adj_list.get(vertex1).add(new Pair(vertex2, weight));
                adj_list.get(vertex2).add(new Pair(vertex1, weight));
            }
        }

        public List<Pair> get_neighbors(String vertex) {
            return adj_list.getOrDefault(vertex, new ArrayList<>());
        }
    }

    static class PriorityQueue {
        List<Pair> elements;

        public PriorityQueue() {
            elements = new ArrayList<>();
        }

        public boolean empty() {
            return elements.isEmpty();
        }

        public void put(String item, int priority) {
            elements.add(new Pair(item, priority));
            elements.sort(Comparator.comparingInt(pair -> pair.weight));
        }

        public String get() {
            return elements.remove(0).item;
        }
    }

    static class Pair {
        String item;
        int weight;

        public Pair(String item, int weight) {
            this.item = item;
            this.weight = weight;
        }
    }

    static Pair dijkstra(Graph graph, String start, String end) {
        PriorityQueue queue = new PriorityQueue();
        queue.put(start, 0);
        Map<String, Integer> distances = new HashMap<>();
        for (String vertex : graph.adj_list.keySet()) {
            distances.put(vertex, Integer.MAX_VALUE);
        }
        distances.put(start, 0);
        Map<String, String> previous = new HashMap<>();
        for (String vertex : graph.adj_list.keySet()) {
            previous.put(vertex, null);
        }

        while (!queue.empty()) {
            String current = queue.get();
            if (current.equals(end)) {
                break;
            }
            for (Pair neighbor : graph.get_neighbors(current)) {
                int distance = distances.get(current) + neighbor.weight;
                if (distance < distances.get(neighbor.item)) {
                    distances.put(neighbor.item, distance);
                    previous.put(neighbor.item, current);
                    queue.put(neighbor.item, distance);
                }
            }
        }

        List<String> path = new ArrayList<>();
        while (end != null) {
            path.add(end);
            end = previous.get(end);
        }
        Collections.reverse(path);
        return new Pair(path.toString(), distances.get("E"));
    }

    public static void main(String[] args) {
        Graph graph = new Graph();
        String[] vertices = {"A", "B", "C", "D", "E"};
        for (String vertex : vertices) {
            graph.add_vertex(vertex);
        }
        graph.add_edge("A", "B", 1);
        graph.add_edge("B", "C", 2);
        graph.add_edge("C", "D", 3);
        graph.add_edge("D", "E", 4);
        graph.add_edge("E", "A", 5);
        Pair result = dijkstra(graph, "A", "E");
        System.out.println("Path: " + result.item);
        System.out.println("Distances: " + result.weight);
    }
}