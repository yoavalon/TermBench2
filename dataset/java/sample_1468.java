import java.util.*;

class Graph {
    private Map<Integer, List<int[]>> nodes;

    public Graph() {
        nodes = new HashMap<>();
    }

    public void add_node(int node) {
        if (!nodes.containsKey(node)) {
            nodes.put(node, new ArrayList<>());
        }
    }

    public void add_edge(int from_node, int to_node, int weight) {
        if (nodes.containsKey(from_node)) {
            nodes.get(from_node).add(new int[]{to_node, weight});
        }
    }
}

public class sample_1468 {
    public static int dijkstra(Graph graph, int start, int end) {
        Map<Integer, Integer> distances = new HashMap<>();
        for (int node : graph.nodes.keySet()) {
            distances.put(node, Integer.MAX_VALUE);
        }
        distances.put(start, 0);
        PriorityQueue<int[]> priority_queue = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        priority_queue.offer(new int[]{0, start});
        while (!priority_queue.isEmpty()) {
            int[] current = priority_queue.poll();
            int current_distance = current[0];
            int current_node = current[1];
            if (current_distance > distances.get(current_node)) {
                continue;
            }
            for (int[] neighbor : graph.nodes.getOrDefault(current_node, Collections.emptyList())) {
                int distance = current_distance + neighbor[1];
                if (distance < distances.get(neighbor[0])) {
                    distances.put(neighbor[0], distance);
                    priority_queue.offer(new int[]{distance, neighbor[0]});
                }
            }
        }
        return distances.get(end);
    }

    public static void main(String[] args) {
        Graph graph = new Graph();
        graph.add_node(1);
        graph.add_node(2);
        graph.add_node(3);
        graph.add_node(4);
        graph.add_edge(1, 2, 10);
        graph.add_edge(1, 3, 15);
        graph.add_edge(2, 3, 7);
        graph.add_edge(2, 4, 12);
        graph.add_edge(3, 4, 10);
        System.out.println(dijkstra(graph, 1, 4));
    }
}