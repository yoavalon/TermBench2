import java.util.*;

public class sample_2608 {

    static class Graph {
        List<Integer> nodes;
        Map<Integer, List<Integer>> adj_list;

        Graph(List<Integer> nodes) {
            this.nodes = nodes;
            this.adj_list = new HashMap<>();
            for (Integer node : nodes) {
                this.adj_list.put(node, new ArrayList<>());
            }
        }

        void add_edge(int node1, int node2) {
            this.adj_list.get(node1).add(node2);
            this.adj_list.get(node2).add(node1);
        }
    }

    static class ShortestPathFinder {
        Graph graph;

        ShortestPathFinder(Graph graph) {
            this.graph = graph;
        }

        int bfs(int start, int end) {
            Queue<Pair> queue = new LinkedList<>();
            queue.add(new Pair(start, 0));
            Set<Integer> visited = new HashSet<>();
            while (!queue.isEmpty()) {
                Pair pair = queue.poll();
                int node = pair.node;
                int dist = pair.dist;
                if (node == end) {
                    return dist;
                }
                if (!visited.contains(node)) {
                    visited.add(node);
                    for (int neighbor : graph.adj_list.get(node)) {
                        queue.add(new Pair(neighbor, dist + 1));
                    }
                }
            }
            return -1;
        }
    }

    static class Pair {
        int node;
        int dist;

        Pair(int node, int dist) {
            this.node = node;
            this.dist = dist;
        }
    }

    public static void main(String[] args) {
        List<Integer> nodes = Arrays.asList(0, 1, 2, 3, 4, 5, 6);
        Graph graph = new Graph(nodes);
        graph.add_edge(0, 1);
        graph.add_edge(1, 2);
        graph.add_edge(2, 3);
        graph.add_edge(3, 4);
        graph.add_edge(4, 5);
        graph.add_edge(5, 6);
        graph.add_edge(0, 3);
        graph.add_edge(3, 6);
        ShortestPathFinder spf = new ShortestPathFinder(graph);
        int result = spf.bfs(0, 6);
        System.out.println(result);
    }
}