import java.util.ArrayList;
import java.util.List;

public class sample_2372 {

    static double distance(int[] node1, int[] node2) {
        int x1 = node1[0], y1 = node1[1];
        int x2 = node2[0], y2 = node2[1];
        return Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }

    static int[] nearest_node(int[][] nodes, int[] current) {
        double min_dist = Double.POSITIVE_INFINITY;
        int[] nearest = null;
        for (int[] node : nodes) {
            double dist = distance(current, node);
            if (dist < min_dist) {
                min_dist = dist;
                nearest = node;
            }
        }
        return nearest;
    }

    static class Graph {
        int[][] nodes;

        Graph(int[][] nodes) {
            this.nodes = nodes;
        }

        List<int[]> find_shortest_path(int[] start, int[] end) {
            List<int[]> path = new ArrayList<>();
            int[] current = start;
            while (!java.util.Arrays.equals(current, end)) {
                path.add(current);
                int[] next_node = nearest_node(nodes, current);
                current = next_node;
            }
            path.add(end);
            return path;
        }
    }

    public static void main(String[] args) {
        int[][] nodes = {{0, 0}, {1, 2}, {3, 4}, {5, 6}, {7, 8}};
        Graph graph = new Graph(nodes);
        int[] start = nodes[0];
        int[] end = nodes[nodes.length - 1];
        while (true) {
            List<int[]> path = graph.find_shortest_path(start, end);
            System.out.print("Path found: ");
            for (int[] node : path) {
                System.out.print("(" + node[0] + ", " + node[1] + ") ");
            }
            System.out.println();
        }
    }
}