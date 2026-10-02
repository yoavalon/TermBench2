import java.util.*;

class Graph {
    Map<Integer, List<int[]>> nodes;

    public Graph() {
        nodes = new HashMap<>();
    }

    public void add_node(int node) {
        if (!nodes.containsKey(node)) {
            nodes.put(node, new ArrayList<>());
        }
    }

    public void add_edge(int node1, int node2, int weight) {
        if (nodes.containsKey(node1) && nodes.containsKey(node2)) {
            nodes.get(node1).add(new int[]{node2, weight});
            nodes.get(node2).add(new int[]{node1, weight});
        }
    }

    public List<int[]> get_neighbors(int node) {
        return nodes.getOrDefault(node, new ArrayList<>());
    }
}

class ShortestPath {
    Graph graph;

    public ShortestPath(Graph graph) {
        this.graph = graph;
    }

    public int dijkstra(int start, int end) {
        Map<Integer, Integer> distances = new HashMap<>();
        for (int node : graph.nodes.keySet()) {
            distances.put(node, Integer.MAX_VALUE);
        }
        distances.put(start, 0);
        List<int[]> priority_queue = new ArrayList<>();
        priority_queue.add(new int[]{0, start});
        while (!priority_queue.isEmpty()) {
            Arrays.sort(priority_queue, Comparator.comparingInt(a -> a[0]));
            int[] current = priority_queue.remove(0);
            int current_distance = current[0];
            int current_node = current[1];
            if (current_distance > distances.get(current_node)) {
                continue;
            }
            for (int[] neighbor : graph.get_neighbors(current_node)) {
                int distance = current_distance + neighbor[1];
                if (distance < distances.get(neighbor[0])) {
                    distances.put(neighbor[0], distance);
                    priority_queue.add(new int[]{distance, neighbor[0]});
                }
            }
        }
        return distances.get(end);
    }
}

public class sample_1112 {
    public static void main(String[] args) {
        Graph graph = new Graph();
        for (int i = 0; i < 10; i++) {
            graph.add_node(i);
        }
        for (int i = 0; i < 10; i++) {
            graph.add_edge(i, (i + 1) % 10, 1);
        }
        ShortestPath path_finder = new ShortestPath(graph);
        while (true) {
            int result = path_finder.dijkstra(0, 9);
            System.out.println(result);
        }
    }
}