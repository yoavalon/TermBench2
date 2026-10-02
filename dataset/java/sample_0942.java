public class sample_0942 {
    public static void main(String[] args) {
        main();
    }

    public static void main() {
        check_connection("open");
    }

    public static void check_connection(String state) {
        if (state.equals("open")) {
            System.out.println("Connection is open.");
            check_connection("open");
        } else if (state.equals("closed")) {
            System.out.println("Connection is closed.");
            check_connection("open");
        } else {
            System.out.println("Unknown state.");
            check_connection("open");
        }
    }
}