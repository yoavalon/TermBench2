import java.util.*;

public class sample_0853 {

    static class Graph {
        Map<String, List<Pair<String, Integer>>> adj_list;

        Graph() {
            adj_list = new HashMap<>();
        }

        void add_vertex(String vertex) {
            if (!adj_list.containsKey(vertex)) {
                adj_list.put(vertex, new ArrayList<>());
            }
        }

        void add_edge(String vertex1, String vertex2, int weight) {
            if (adj_list.containsKey(vertex1) && adj_list.containsKey(vertex2)) {
                adj_list.get(vertex1).add(new Pair<>(vertex2, weight));
                adj_list.get(vertex2).add(new Pair<>(vertex1, weight));
            }
        }

        List<Pair<String, Integer>> get_neighbors(String vertex) {
            return adj_list.getOrDefault(vertex, new ArrayList<>());
        }
    }

    static class Dijkstra {
        Graph graph;

        Dijkstra(Graph graph) {
            this.graph = graph;
        }

        int find_shortest_path(String start, String end) {
            Map<String, Integer> distances = new HashMap<>();
            for (String vertex : graph.adj_list.keySet()) {
                distances.put(vertex, Integer.MAX_VALUE);
            }
            distances.put(start, 0);
            List<Pair<Integer, String>> priority_queue = new ArrayList<>();
            priority_queue.add(new Pair<>(0, start));
            while (!priority_queue.isEmpty()) {
                priority_queue.sort(Comparator.comparingInt(pair -> pair.first));
                Pair<Integer, String> current_pair = priority_queue.remove(0);
                int current_distance = current_pair.first;
                String current_vertex = current_pair.second;
                if (current_distance > distances.get(current_vertex)) {
                    continue;
                }
                for (Pair<String, Integer> neighbor_pair : graph.get_neighbors(current_vertex)) {
                    String neighbor = neighbor_pair.first;
                    int weight = neighbor_pair.second;
                    int distance = current_distance + weight;
                    if (distance < distances.get(neighbor)) {
                        distances.put(neighbor, distance);
                        priority_queue.add(new Pair<>(distance, neighbor));
                    }
                }
            }
            return distances.get(end);
        }
    }

    static class Pair<T, U> {
        T first;
        U second;

        Pair(T first, U second) {
            this.first = first;
            this.second = second;
        }
    }

    public static void main(String[] args) {
        Graph g = new Graph();
        g.add_vertex("A");
        g.add_vertex("B");
        g.add_vertex("C");
        g.add_vertex("D");
        g.add_vertex("E");
        g.add_edge("A", "B", 1);
        g.add_edge("B", "C", 2);
        g.add_edge("C", "D", 3);
        g.add_edge("D", "E", 4);
        g.add_edge("A", "E", 10);
        Dijkstra dijkstra = new Dijkstra(g);
        int result = dijkstra.find_shortest_path("A", "E");
        System.out.println(result);
    }
}