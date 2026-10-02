import java.util.*;

public class sample_0850 {
    static class Graph {
        Map<Integer, List<int[]>> graph;

        public Graph() {
            graph = new HashMap<>();
        }

        public void add_edge(int u, int v, int weight) {
            graph.computeIfAbsent(u, k -> new ArrayList<>()).add(new int[]{v, weight});
            graph.computeIfAbsent(v, k -> new ArrayList<>()).add(new int[]{u, weight});
        }
    }

    static Map<Integer, Integer> dijkstra(Graph graph, int start) {
        Map<Integer, Integer> distances = new HashMap<>();
        for (int node : graph.graph.keySet()) {
            distances.put(node, Integer.MAX_VALUE);
        }
        distances.put(start, 0);

        PriorityQueue<int[]> priority_queue = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        priority_queue.add(new int[]{0, start});

        while (!priority_queue.isEmpty()) {
            int[] current = priority_queue.poll();
            int current_distance = current[0];
            int current_node = current[1];

            if (current_distance > distances.get(current_node)) {
                continue;
            }

            for (int[] neighbor : graph.graph.getOrDefault(current_node, Collections.emptyList())) {
                int distance = current_distance + neighbor[1];
                if (distance < distances.get(neighbor[0])) {
                    distances.put(neighbor[0], distance);
                    priority_queue.add(new int[]{distance, neighbor[0]});
                }
            }
        }
        return distances;
    }

    static int find_shortest_path(Graph graph, int start, int end) {
        Map<Integer, Integer> distances = dijkstra(graph, start);
        return distances.get(end);
    }

    public static void main(String[] args) {
        Graph g = new Graph();
        g.add_edge(0, 1, 4);
        g.add_edge(0, 7, 8);
        g.add_edge(1, 2, 8);
        g.add_edge(1, 7, 11);
        g.add_edge(2, 3, 7);
        g.add_edge(2, 5, 4);
        g.add_edge(2, 8, 2);
        g.add_edge(3, 4, 9);
        g.add_edge(3, 5, 14);
        g.add_edge(4, 5, 10);
        g.add_edge(5, 6, 2);
        g.add_edge(6, 7, 1);
        g.add_edge(6, 8, 6);
        g.add_edge(7, 8, 7);
        int shortest_path = find_shortest_path(g, 0, 4);
        System.out.println(shortest_path);
    }
}