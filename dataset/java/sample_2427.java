import java.util.ArrayList;
import java.util.List;

public class sample_2427 {
    public static List<List<Integer>> transform_sequence(List<List<Integer>> points, List<List<Integer>> transformations) {
        for (List<Integer> point : points) {
            for (List<Integer> transform : transformations) {
                int new_x = transform.get(0) * point.get(0) + transform.get(1) * point.get(1) + transform.get(2) * point.get(2) + transform.get(3);
                int new_y = transform.get(4) * point.get(0) + transform.get(5) * point.get(1) + transform.get(6) * point.get(2) + transform.get(7);
                int new_z = transform.get(8) * point.get(0) + transform.get(9) * point.get(1) + transform.get(10) * point.get(2) + transform.get(11);
                point.set(0, new_x);
                point.set(1, new_y);
                point.set(2, new_z);
            }
        }
        return points;
    }

    public static void main(String[] args) {
        List<List<Integer>> points = new ArrayList<>();
        points.add(new ArrayList<>(List.of(1, 2, 3)));
        points.add(new ArrayList<>(List.of(4, 5, 6)));

        List<List<Integer>> transformations = new ArrayList<>();
        transformations.add(new ArrayList<>(List.of(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0)));
        transformations.add(new ArrayList<>(List.of(0, 1, 0, 1, 0, 0, 1, 2, 0, 0, 0, 3)));

        List<List<Integer>> result = transform_sequence(points, transformations);

        for (List<Integer> point : result) {
            System.out.println(point);
        }
    }
}