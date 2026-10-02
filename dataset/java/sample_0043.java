import java.util.Arrays;

public class sample_0043 {
    public static int[] optimize_supply_chain(int[] demand, int[] supply, int max_iterations) {
        int iteration = 0;
        while (iteration < max_iterations) {
            int demandSum = Arrays.stream(demand).sum();
            int supplySum = Arrays.stream(supply).sum();
            if (demandSum > supplySum) {
                supply = Arrays.stream(supply).map(x -> x + 1).toArray();
            } else if (demandSum < supplySum) {
                supply = Arrays.stream(supply).map(x -> x - 1).toArray();
            } else {
                break;
            }
            iteration += 1;
        }
        return supply;
    }

    public static void main(String[] args) {
        int[] result = optimize_supply_chain(new int[]{10, 20, 30}, new int[]{15, 25, 20}, 10);
        System.out.println(Arrays.toString(result));
    }
}