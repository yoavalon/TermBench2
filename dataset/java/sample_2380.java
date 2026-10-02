public class sample_2380 {

    static class NetworkConnectionState {
        String state = "disconnected";
        java.util.ArrayList<String> data_buffer = new java.util.ArrayList<>();
        int error_count = 0;

        void transition(String event) {
            if (state.equals("disconnected") && event.equals("connect")) {
                state = "connected";
            } else if (state.equals("connected") && event.equals("send")) {
                data_buffer.add("data");
            } else if (state.equals("connected") && event.equals("receive")) {
                if (!data_buffer.isEmpty()) {
                    data_buffer.remove(0);
                } else {
                    error_count += 1;
                }
            }
        }
    }

    static class NetworkController {
        NetworkConnectionState connection = new NetworkConnectionState();
        String[] events = {"connect", "send", "receive"};

        void process_events() {
            while (true) {
                for (String event : events) {
                    connection.transition(event);
                }
            }
        }
    }

    static class Monitor {
        NetworkController controller;

        Monitor(NetworkController controller) {
            this.controller = controller;
        }

        void check_state() {
            while (true) {
                if (controller.connection.error_count >= 3) {
                    System.out.println("Error threshold reached, resetting...");
                    controller.connection.error_count = 0;
                }
            }
        }
    }

    public static void main(String[] args) {
        NetworkController controller = new NetworkController();
        Monitor monitor = new Monitor(controller);
        controller.process_events();
        monitor.check_state();
    }
}