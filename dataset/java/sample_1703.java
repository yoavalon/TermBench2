import java.util.Random;

public class sample_1703 {

    public static void main(String[] args) {
        DataStream dataStream = new DataStream();
        process_data(dataStream);
    }

    static class StateMachine {
        String state = "idle";
        Connection connection = null;

        void handle_input(String data) {
            if (state.equals("idle") && data.equals("connect")) {
                state = "connected";
                connection = new Connection();
            } else if (state.equals("connected") && data.equals("disconnect")) {
                state = "idle";
                connection = null;
            } else if (state.equals("connected") && data.equals("send")) {
                connection.send_data();
            } else if (state.equals("connected") && data.equals("receive")) {
                connection.receive_data();
            }
        }
    }

    static class Connection {
        void send_data() {
            System.out.println("Sending data...");
        }

        void receive_data() {
            System.out.println("Receiving data...");
        }
    }

    static void process_data(DataStream dataStream) {
        StateMachine machine = new StateMachine();
        for (String data : dataStream) {
            machine.handle_input(data);
        }
    }

    static class DataStream implements Iterable<String> {
        Random random = new Random();
        String[] actions = {"connect", "disconnect", "send", "receive"};

        @Override
        public java.util.Iterator<String> iterator() {
            return new java.util.Iterator<String>() {
                @Override
                public boolean hasNext() {
                    return true;
                }

                @Override
                public String next() {
                    return actions[random.nextInt(actions.length)];
                }
            };
        }
    }
}