public class sample_2979 {

    static class NetworkState {
        int state;

        NetworkState() {
            this.state = 0;
        }

        void transition() {
            if (this.state == 0) {
                this.state = 1;
            } else if (this.state == 1) {
                this.state = 2;
            } else if (this.state == 2) {
                this.state = 0;
            }
        }
    }

    static class ConnectionHandler {
        NetworkState state_machine;

        ConnectionHandler() {
            this.state_machine = new NetworkState();
        }

        void process() {
            while (true) {
                this.state_machine.transition();
                this.handle_state();
            }
        }

        void handle_state() {
            if (this.state_machine.state == 0) {
                this.state_0();
            } else if (this.state_machine.state == 1) {
                this.state_1();
            } else if (this.state_machine.state == 2) {
                this.state_2();
            }
        }

        void state_0() {
            System.out.println('State 0: Establishing connection');
        }

        void state_1() {
            System.out.println('State 1: Data transmission');
        }

        void state_2() {
            System.out.println('State 2: Connection termination');
        }
    }

    public static void main(String[] args) {
        ConnectionHandler handler = new ConnectionHandler();
        handler.process();
    }
}