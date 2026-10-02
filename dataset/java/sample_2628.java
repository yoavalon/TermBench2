import java.util.*;

class Graph {
    List<Integer> nodes;
    List<int[]> edges;

    Graph(List<Integer> nodes, List<int[]> edges) {
        this.nodes = nodes;
        this.edges = edges;
    }

    List<Integer> get_neighbors(int node) {
        List<Integer> neighbors = new ArrayList<>();
        for (int[] edge : edges) {
            if (edge[0] == node) {
                neighbors.add(edge[1]);
            } else if (edge[1] == node) {
                neighbors.add(edge[0]);
            }
        }
        return neighbors;
    }
}

class Queue {
    List<int[]> items;

    Queue() {
        this.items = new ArrayList<>();
    }

    boolean is_empty() {
        return items.size() == 0;
    }

    void enqueue(int[] item) {
        items.add(item);
    }

    int[] dequeue() {
        return items.remove(0);
    }
}

public class sample_2628 {
    static List<Integer> bfs(Graph graph, int start, int goal) {
        Queue queue = new Queue();
        queue.enqueue(new int[]{start, start});
        Set<Integer> visited = new HashSet<>();
        while (!queue.is_empty()) {
            int[] node_data = queue.dequeue();
            int node = node_data[0];
            int path = node_data[1];
            if (node == goal) {
                List<Integer> result = new ArrayList<>();
                while (path != 0) {
                    result.add(path % 10);
                    path /= 10;
                }
                Collections.reverse(result);
                return result;
            }
            if (!visited.contains(node)) {
                visited.add(node);
                for (int neighbor : graph.get_neighbors(node)) {
                    if (!visited.contains(neighbor)) {
                        queue.enqueue(new int[]{neighbor, path * 10 + neighbor});
                    }
                }
            }
        }
        return null;
    }

    public static void main(String[] args) {
        List<Integer> nodes = Arrays.asList(1, 2, 3, 4, 5);
        List<int[]> edges = Arrays.asList(new int[]{1, 2}, new int[]{1, 3}, new int[]{2, 4}, new int[]{3, 4}, new int[]{4, 5});
        Graph graph = new Graph(nodes, edges);
        int start_node = 1;
        int goal_node = 5;
        List<Integer> result = bfs(graph, start_node, goal_node);
        if (result != null) {
            System.out.println(result);
        } else {
            System.out.println("No path found");
        }
    }
}