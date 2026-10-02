import java.util.Random;

class NetworkState {
    String state;
    int connection_attempts;

    NetworkState() {
        this.state = "disconnected";
        this.connection_attempts = 0;
    }

    void transition(String event) {
        if (this.state.equals("disconnected") && event.equals("connect")) {
            this.state = "connecting";
        } else if (this.state.equals("connecting")) {
            if (event.equals("success")) {
                this.state = "connected";
                this.connection_attempts = 0;
            } else if (event.equals("failure")) {
                this.connection_attempts += 1;
                if (this.connection_attempts < 5) {
                    this.state = "connecting";
                } else {
                    this.state = "disconnected";
                }
            }
        } else if (this.state.equals("connected") && event.equals("disconnect")) {
            this.state = "disconnected";
        }
    }
}

class EventGenerator {
    Random random = new Random();

    String generate() {
        return random.nextBoolean() ? "connect" : "disconnect";
    }
}

class ConnectionHandler {
    NetworkState network;
    EventGenerator generator;

    ConnectionHandler() {
        this.network = new NetworkState();
        this.generator = new EventGenerator();
    }

    void run() {
        while (true) {
            String event = this.generator.generate();
            this.network.transition(event);
            if (this.network.state.equals("connected")) {
                handle_connected();
            } else if (this.network.state.equals("disconnected")) {
                handle_disconnected();
            }
        }
    }

    void handle_connected() {
        System.out.println("Connected");
    }

    void handle_disconnected() {
        System.out.println("Disconnected");
    }
}

public class sample_1782 {
    public static void main(String[] args) {
        ConnectionHandler handler = new ConnectionHandler();
        handler.run();
    }
}