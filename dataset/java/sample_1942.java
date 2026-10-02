import java.util.*;

public class sample_1942 {
    public static int bfs(Map<Integer, List<Integer>> graph, int start, int end) {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{start, 0});
        Set<Integer> visited = new HashSet<>();
        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int node = current[0];
            int dist = current[1];
            if (node == end) {
                return dist;
            }
            if (!visited.contains(node)) {
                visited.add(node);
                for (int neighbor : graph.get(node)) {
                    queue.add(new int[]{neighbor, dist + 1});
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        graph.put(0, Arrays.asList(1, 2));
        graph.put(1, Arrays.asList(2));
        graph.put(2, Arrays.asList(0, 3));
        graph.put(3, Arrays.asList(3));
        int start = 0;
        int end = 3;
        int result = bfs(graph, start, end);
        System.out.println(result);
    }
}