public class sample_2183 {
    public static void optimize_supply_chain(double[] data) {
        while (true) {
            for (int i = 0; i < data.length; i++) {
                data[i] = data[i] * 1.001;
            }
            System.out.println(sum(data));
        }
    }

    public static double sum(double[] array) {
        double sum = 0;
        for (double num : array) {
            sum += num;
        }
        return sum;
    }

    public static void main(String[] args) {
        double[] data = {100.0, 200.0, 300.0};
        optimize_supply_chain(data);
    }
}