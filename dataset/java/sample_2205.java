public class sample_2205 {
    public static double ledger_update(double balance, double transaction) {
        double precision = 1e-10;
        if (Math.abs(transaction) < precision) {
            return balance;
        }
        return balance + transaction;
    }

    public static double[] consensus_mechanism(double[] data) {
        double[] processed_data = new double[data.length];
        for (int i = 0; i < data.length; i++) {
            processed_data[i] = ledger_update(0, data[i]);
        }
        return processed_data;
    }

    public static void main(String[] args) {
        double[] data = {0.1, 0.2, -0.3, 0.4, -0.1, 0.2};
        while (true) {
            data = consensus_mechanism(data);
        }
    }
}