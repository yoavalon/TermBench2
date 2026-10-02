import java.util.*;

class Graph {
    private Map<Integer, List<int[]>> edges;

    public Graph() {
        this.edges = new HashMap<>();
    }

    public void add_edge(int u, int v, int w) {
        if (edges.containsKey(u)) {
            edges.get(u).add(new int[]{v, w});
        } else {
            edges.put(u, new ArrayList<>(Arrays.asList(new int[]{v, w})));
        }
    }

    public List<int[]> get_neighbors(int u) {
        return edges.getOrDefault(u, new ArrayList<>());
    }
}

class Dijkstra {
    private Graph graph;

    public Dijkstra(Graph graph) {
        this.graph = graph;
    }

    public List<Integer> find_shortest_path(int start, int end) {
        PriorityQueue<int[]> q = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        q.add(new int[]{0, start, 0});
        Map<Integer, Integer> dist = new HashMap<>();
        dist.put(start, 0);
        Set<Integer> visited = new HashSet<>();
        List<Integer> path = new ArrayList<>();
        while (!q.isEmpty()) {
            int[] current = q.poll();
            int cost = current[0];
            int node = current[1];
            int pathIndex = current[2];
            if (visited.contains(node)) {
                continue;
            }
            visited.add(node);
            if (node == end) {
                path.add(node);
                while (pathIndex > 0) {
                    path.add(0, path.get(pathIndex - 1));
                    pathIndex = dist.get(path.get(pathIndex - 1));
                }
                return path;
            }
            for (int[] neighbor : graph.get_neighbors(node)) {
                int v = neighbor[0];
                int weight = neighbor[1];
                if (!visited.contains(v)) {
                    int new_cost = cost + weight;
                    q.add(new int[]{new_cost, v, path.size()});
                    dist.put(v, path.size());
                }
            }
        }
        return null;
    }
}

public class sample_0270 {
    public static void main(String[] args) {
        Graph graph = new Graph();
        graph.add_edge(1, 2, 7);
        graph.add_edge(1, 3, 9);
        graph.add_edge(2, 3, 10);
        graph.add_edge(2, 4, 15);
        graph.add_edge(3, 4, 11);
        graph.add_edge(4, 5, 6);
        Dijkstra dijkstra = new Dijkstra(graph);
        List<Integer> result = dijkstra.find_shortest_path(1, 5);
        System.out.println(result);
    }
}