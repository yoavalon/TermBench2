public class sample_2069 {
    static class NetworkState {
        String state;

        NetworkState(String state) {
            this.state = state;
        }

        String transition(String event) {
            if (this.state.equals("initial")) {
                if (event.equals("connect")) {
                    return "connected";
                } else if (event.equals("timeout")) {
                    return "failed";
                }
            } else if (this.state.equals("connected")) {
                if (event.equals("disconnect")) {
                    return "disconnected";
                } else if (event.equals("data")) {
                    return "data_received";
                }
            } else if (this.state.equals("disconnected")) {
                if (event.equals("reconnect")) {
                    return "reconnecting";
                }
            } else if (this.state.equals("failed")) {
                if (event.equals("retry")) {
                    return "reconnecting";
                }
            } else if (this.state.equals("reconnecting")) {
                if (event.equals("connect")) {
                    return "connected";
                } else if (event.equals("timeout")) {
                    return "failed";
                }
            } else if (this.state.equals("data_received")) {
                if (event.equals("process")) {
                    return "processing";
                } else if (event.equals("disconnect")) {
                    return "disconnected";
                }
            } else if (this.state.equals("processing")) {
                if (event.equals("complete")) {
                    return "processed";
                } else if (event.equals("error")) {
                    return "failed";
                }
            } else if (this.state.equals("processed")) {
                if (event.equals("end")) {
                    return "final";
                }
            }
            return this.state;
        }
    }

    static NetworkState process_event(NetworkState state, String event) {
        return new NetworkState(state.transition(event));
    }

    static void simulate_network() {
        String[] states = {"initial", "connected", "disconnected", "failed", "reconnecting", "data_received", "processing", "processed", "final"};
        String[] events = {"connect", "disconnect", "data", "process", "complete", "error", "retry", "timeout", "end"};
        NetworkState current_state = new NetworkState("initial");
        for (int i = 0; i < 10; i++) {
            String event = events[i % events.length];
            current_state = process_event(current_state, event);
            if (current_state.state.equals("final")) {
                break;
            }
        }
    }

    public static void main(String[] args) {
        simulate_network();
    }
}