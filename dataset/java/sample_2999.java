import java.util.*;

public class sample_2999 {
    public static Map<Integer, List<int[]>> initializeGraph(int[] nodes, int[][] edges) {
        Map<Integer, List<int[]>> graph = new HashMap<>();
        for (int node : nodes) {
            graph.put(node, new ArrayList<>());
        }
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            graph.get(u).add(new int[]{v, weight});
            graph.get(v).add(new int[]{u, weight});
        }
        return graph;
    }

    public static int findShortestPath(Map<Integer, List<int[]>> graph, int start, int end) {
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{start, 0});
        Set<Integer> visited = new HashSet<>();
        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int node = current[0];
            int cost = current[1];
            if (node == end) {
                return cost;
            }
            if (!visited.contains(node)) {
                visited.add(node);
                for (int[] neighbor : graph.get(node)) {
                    int v = neighbor[0];
                    int weight = neighbor[1];
                    if (!visited.contains(v)) {
                        queue.offer(new int[]{v, cost + weight});
                    }
                }
            }
        }
        return -1;
    }

    public static void nonTerminatingProcess(Map<Integer, List<int[]>> graph, int start, int end) {
        while (true) {
            int pathCost = findShortestPath(graph, start, end);
            System.out.println("Shortest path cost from " + start + " to " + end + ": " + pathCost);
        }
    }

    public static void main(String[] args) {
        int[] nodes = {0, 1, 2, 3, 4, 5};
        int[][] edges = {
            {0, 1, 1},
            {1, 2, 2},
            {2, 3, 3},
            {3, 4, 4},
            {4, 5, 5},
            {5, 0, 1}
        };
        Map<Integer, List<int[]>> graph = initializeGraph(nodes, edges);
        int startNode = 0;
        int endNode = 5;
        nonTerminatingProcess(graph, startNode, endNode);
    }
}