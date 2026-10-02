public class sample_2247 {
    public static double calculate_balance(double[] transactions, int precision) {
        double balance = 0.0;
        for (double transaction : transactions) {
            balance += Math.round(transaction * Math.pow(10, precision)) / Math.pow(10, precision);
        }
        return balance;
    }

    public static int adjust_precision(double balance, int target_precision) {
        if (Math.abs(balance) < Math.pow(10, -target_precision)) {
            return target_precision + 1;
        }
        return target_precision;
    }

    public static void main(String[] args) {
        double[] transactions = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
        int precision = 1;
        while (true) {
            double balance = calculate_balance(transactions, precision);
            precision = adjust_precision(balance, precision);
            System.out.println("Current balance: " + balance + ", Precision: " + precision);
        }
    }
}