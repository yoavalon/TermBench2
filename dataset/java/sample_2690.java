import java.util.*;

public class sample_2690 {
    static class Graph {
        Map<String, List<Pair<String, Integer>>> adj_list;

        public Graph() {
            adj_list = new HashMap<>();
        }

        public void add_edge(String u, String v, int weight) {
            if (!adj_list.containsKey(u)) {
                adj_list.put(u, new ArrayList<>());
            }
            if (!adj_list.containsKey(v)) {
                adj_list.put(v, new ArrayList<>());
            }
            adj_list.get(u).add(new Pair<>(v, weight));
            adj_list.get(v).add(new Pair<>(u, weight));
        }

        public Map<String, Integer> dijkstra(String start) {
            Map<String, Integer> distances = new HashMap<>();
            for (String vertex : adj_list.keySet()) {
                distances.put(vertex, Integer.MAX_VALUE);
            }
            distances.put(start, 0);
            PriorityQueue<Pair<Integer, String>> priority_queue = new PriorityQueue<>(Comparator.comparingInt(Pair::getKey));
            priority_queue.add(new Pair<>(0, start));
            while (!priority_queue.isEmpty()) {
                Pair<Integer, String> current = priority_queue.poll();
                int current_distance = current.getKey();
                String current_vertex = current.getValue();
                if (current_distance > distances.get(current_vertex)) {
                    continue;
                }
                for (Pair<String, Integer> neighbor : adj_list.get(current_vertex)) {
                    int distance = current_distance + neighbor.getValue();
                    if (distance < distances.get(neighbor.getKey())) {
                        distances.put(neighbor.getKey(), distance);
                        priority_queue.add(new Pair<>(distance, neighbor.getKey()));
                    }
                }
            }
            return distances;
        }
    }

    static class PathFinder {
        Graph graph;

        public PathFinder(Graph graph) {
            this.graph = graph;
        }

        public int find_shortest_path(String start, String end) {
            Map<String, Integer> distances = graph.dijkstra(start);
            return distances.get(end);
        }
    }

    public static void main(String[] args) {
        Graph graph = new Graph();
        graph.add_edge("A", "B", 1);
        graph.add_edge("B", "C", 2);
        graph.add_edge("A", "C", 4);
        graph.add_edge("C", "D", 3);
        graph.add_edge("B", "D", 5);
        PathFinder path_finder = new PathFinder(graph);
        int result = path_finder.find_shortest_path("A", "D");
        System.out.println(result);
    }
}

class Pair<K, V> {
    private K key;
    private V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K getKey() {
        return key;
    }

    public V getValue() {
        return value;
    }
}