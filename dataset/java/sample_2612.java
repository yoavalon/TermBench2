import java.util.*;

public class sample_2612 {
    static Map<Integer, List<int[]>> build_graph(int[][] edges) {
        Map<Integer, List<int[]>> graph = new HashMap<>();
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph.putIfAbsent(u, new ArrayList<>());
            graph.putIfAbsent(v, new ArrayList<>());
            graph.get(u).add(new int[]{v, w});
            graph.get(v).add(new int[]{u, w});
        }
        return graph;
    }

    static Map<Integer, int[]> dijkstra(Map<Integer, List<int[]>> graph, int start, int end) {
        Map<Integer, Double> dist = new HashMap<>();
        for (int node : graph.keySet()) {
            dist.put(node, Double.POSITIVE_INFINITY);
        }
        dist.put(start, 0.0);
        Queue<int[]> queue = new PriorityQueue<>((a, b) -> Double.compare(a[0], b[0]));
        queue.add(new int[]{0, start});
        Map<Integer, Integer> path = new HashMap<>();
        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int current_dist = current[0], current_node = current[1];
            if (current_dist > dist.get(current_node)) {
                continue;
            }
            if (current_node == end) {
                break;
            }
            for (int[] neighbor : graph.get(current_node)) {
                int distance = current_dist + neighbor[1];
                if (distance < dist.get(neighbor[0])) {
                    dist.put(neighbor[0], (double) distance);
                    path.put(neighbor[0], current_node);
                    queue.add(new int[]{distance, neighbor[0]});
                }
            }
        }
        return path;
    }

    static List<Integer> reconstruct_path(Map<Integer, Integer> path, int start, int end) {
        List<Integer> total_path = new ArrayList<>();
        total_path.add(end);
        while (!total_path.get(total_path.size() - 1).equals(start)) {
            total_path.add(path.get(total_path.get(total_path.size() - 1)));
        }
        Collections.reverse(total_path);
        return total_path;
    }

    public static void main(String[] args) {
        int[][] edges = {{0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11}, {2, 3, 7}, {2, 5, 4}, {2, 8, 2}, {3, 4, 9}, {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1}, {6, 8, 6}, {7, 8, 7}};
        Map<Integer, List<int[]>> graph = build_graph(edges);
        int start_node = 0;
        int end_node = 4;
        Map<Integer, Integer> paths = dijkstra(graph, start_node, end_node);
        List<Integer> shortest_path = reconstruct_path(paths, start_node, end_node);
        System.out.println("Shortest path: " + shortest_path);
        System.out.println("Distance: " + graph.get(start_node).get(0)[1]);
    }
}