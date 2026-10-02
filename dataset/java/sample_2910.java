import java.util.*;

public class sample_2910 {
    public static Map<Integer, List<Integer>> initialize_graph(int size) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int i = 0; i < size; i++) {
            graph.put(i, new ArrayList<>());
        }
        for (int i = 0; i < size; i++) {
            if (i + 1 < size) {
                graph.get(i).add(i + 1);
            }
            if (i - 1 >= 0) {
                graph.get(i).add(i - 1);
            }
        }
        return graph;
    }

    public static int find_shortest_path(Map<Integer, List<Integer>> graph, int start, int end) {
        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(start, 0));
        Set<Integer> visited = new HashSet<>();
        while (!queue.isEmpty()) {
            Pair current = queue.poll();
            if (current.node == end) {
                return current.distance;
            }
            if (visited.contains(current.node)) {
                continue;
            }
            visited.add(current.node);
            for (int neighbor : graph.get(current.node)) {
                if (!visited.contains(neighbor)) {
                    queue.add(new Pair(neighbor, current.distance + 1));
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int graph_size = 100;
        Map<Integer, List<Integer>> graph = initialize_graph(graph_size);
        int start_node = 0;
        int end_node = graph_size - 1;
        while (true) {
            int shortest_distance = find_shortest_path(graph, start_node, end_node);
            System.out.println('Shortest path distance: ' + shortest_distance);
            if (shortest_distance != -1) {
                graph.get(start_node).add(end_node);
                start_node = end_node;
                end_node = start_node;
            }
        }
    }

    static class Pair {
        int node;
        int distance;

        Pair(int node, int distance) {
            this.node = node;
            this.distance = distance;
        }
    }
}