public class sample_1579 {
    public static void main(String[] args) {
        int altitude = 30000;
        while (true) {
            if (altitude > 10000) {
                altitude -= 1000;
            }
            System.out.println("Current altitude: " + altitude + " feet");
        }
    }
}