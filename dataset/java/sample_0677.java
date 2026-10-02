public class sample_0677 {
    public static void plan_altitude(int x, int y, int z, int[] result) {
        if (z <= 0) {
            result[0] = x;
            result[1] = y;
            result[2] = z;
        } else {
            plan_altitude(x + 1, y + 2, z - 1, result);
        }
    }

    public static void main(String[] args) {
        int[] result = new int[3];
        plan_altitude(0, 0, 5, result);
        System.out.println(result[0] + " " + result[1] + " " + result[2]);
    }
}