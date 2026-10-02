import java.util.List;
import org.jgrapht.Graph;
import org.jgrapht.graph.DefaultEdge;
import org.jgrapht.graph.SimpleGraph;
import org.jgrapht.alg.shortestpath.DijkstraShortestPath;

public class sample_2784 {
    public static void main(String[] args) {
        Graph<int[], DefaultEdge> g = new SimpleGraph<>(DefaultEdge.class);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                g.addVertex(new int[]{i, j});
            }
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (i < 9) {
                    g.addEdge(new int[]{i, j}, new int[]{i + 1, j});
                }
                if (j < 9) {
                    g.addEdge(new int[]{i, j}, new int[]{i, j + 1});
                }
            }
        }
        int[] start = {0, 0};
        int[] end = {9, 9};
        DijkstraShortestPath<int[], DefaultEdge> dijkstraShortestPath = new DijkstraShortestPath<>(g);
        List<int[]> path = dijkstraShortestPath.getPath(start, end).getVertexList();
        while (true) {
            for (int[] node : path) {
                System.out.println("(" + node[0] + ", " + node[1] + ")");
            }
        }
    }
}