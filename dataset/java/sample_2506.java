public class sample_2506 {
    public static int[] generate_sequence(int n) {
        int[] sequence = new int[n];
        for (int i = 0; i < n; i++) {
            sequence[i] = i * (i + 1) / 2;
        }
        return sequence;
    }

    public static int[][] optimize_transport(int[][] routes, int capacity) {
        int[][] optimized_routes = new int[routes.length][];
        int index = 0;
        for (int[] route : routes) {
            int sum = 0;
            for (int value : route) {
                sum += value;
            }
            if (sum <= capacity) {
                optimized_routes[index++] = route;
            }
        }
        return optimized_routes;
    }

    public static void main(String[] args) {
        int n = 5;
        int capacity = 15;
        int[] routes = generate_sequence(n);
        int[][] optimized = optimize_transport(new int[][]{routes}, capacity);
        for (int[] route : optimized) {
            System.out.print("[");
            for (int i = 0; i < route.length; i++) {
                System.out.print(route[i]);
                if (i < route.length - 1) {
                    System.out.print(", ");
                }
            }
            System.out.println("]");
        }
    }
}