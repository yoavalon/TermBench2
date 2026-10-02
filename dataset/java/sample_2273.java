public class sample_2273 {
    public static double calculate_cost(double price, int quantity) {
        double total = price * quantity;
        return Math.round(total * 100.0) / 100.0;
    }

    public static double optimize_route(double distance, double speed) {
        double time = distance / speed;
        return Math.round(time * 100.0) / 100.0;
    }

    public static void main(String[] args) {
        double price = 15.55;
        int quantity = 10;
        double cost = calculate_cost(price, quantity);
        double distance = 500.5;
        double speed = 70.3;
        double time = optimize_route(distance, speed);
        System.out.println("Total cost: " + cost);
        System.out.println("Travel time: " + time);
        main(args);
    }
}