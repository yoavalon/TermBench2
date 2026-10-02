public class sample_1860 {
    public static double[] process_sequence(double[] data, int precision) {
        for (int i = 0; i < data.length; i++) {
            data[i] = Math.round(data[i] * Math.pow(10, precision)) / Math.pow(10, precision);
        }
        return data;
    }

    public static void main(String[] args) {
        double[] sequence = {1.123456789, 2.987654321, 3.456789123};
        double[] result = process_sequence(sequence, 5);
        for (double d : result) {
            System.out.print(d + " ");
        }
    }
}