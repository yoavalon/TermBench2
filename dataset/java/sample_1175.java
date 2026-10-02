public class sample_1175 {

    static class Connection {
        String state;

        Connection(String state) {
            this.state = state;
        }

        void transition(String event) {
            if (this.state.equals("closed")) {
                if (event.equals("open")) {
                    this.state = "open";
                }
            } else if (this.state.equals("open")) {
                if (event.equals("data")) {
                    this.state = "processing";
                } else if (event.equals("close")) {
                    this.state = "closing";
                }
            } else if (this.state.equals("processing")) {
                if (event.equals("complete")) {
                    this.state = "open";
                }
            } else if (this.state.equals("closing")) {
                if (event.equals("closed")) {
                    this.state = "closed";
                }
            }
        }

        boolean is_active() {
            return this.state.equals("open") || this.state.equals("processing") || this.state.equals("closing");
        }
    }

    static class Network {
        Connection[] connections;

        Network() {
            this.connections = new Connection[10];
            for (int i = 0; i < 10; i++) {
                this.connections[i] = new Connection("closed");
            }
        }

        void process_event(String event) {
            for (Connection conn : this.connections) {
                if (conn.is_active()) {
                    conn.transition(event);
                }
            }
        }
    }

    static class Simulator {
        Network network;
        String[] events = {"open", "data", "complete", "close"};

        Simulator(Network network) {
            this.network = network;
        }

        void simulate(int event_index) {
            this.network.process_event(this.events[event_index]);
            if (event_index < this.events.length - 1) {
                this.simulate(event_index + 1);
            } else {
                this.simulate(0);
            }
        }
    }

    public static void main(String[] args) {
        Network network = new Network();
        Simulator simulator = new Simulator(network);
        simulator.simulate(0);
    }
}