public class sample_1291 {
    public static void main(String[] args) {
        import java.util.Random;
        Random random = new Random();
        int supply = 100;
        int demand = random.nextInt(101) + 50;
        if (supply < demand) {
            System.out.println('Supply chain disruption detected.');
        } else {
            System.out.println('Supply chain stable.');
        }
    }
}