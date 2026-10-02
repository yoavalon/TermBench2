import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class NetworkStateMachine {
    String state;
    List<String> data;

    NetworkStateMachine() {
        this.state = "disconnected";
        this.data = new ArrayList<>();
    }

    void transition(String event) {
        if (this.state.equals("disconnected") && event.equals("connect")) {
            this.state = "connected";
        } else if (this.state.equals("connected") && event.equals("send")) {
            this.data.add("data");
        } else if (this.state.equals("connected") && event.equals("disconnect")) {
            this.state = "disconnected";
            this.data.clear();
        }
    }

    void process_events(List<String> events) {
        for (String event : events) {
            this.transition(event);
        }
    }

    Object[] get_status() {
        return new Object[]{this.state, this.data};
    }
}

List<String> generate_events(int count) {
    Random random = new Random();
    List<String> events = new ArrayList<>();
    for (int i = 0; i < count; i++) {
        if (random.nextDouble() < 0.3) {
            events.add("connect");
        } else if (random.nextDouble() < 0.5) {
            events.add("send");
        } else {
            events.add("disconnect");
        }
    }
    return events;
}

public class sample_2040 {
    public static void main(String[] args) {
        NetworkStateMachine state_machine = new NetworkStateMachine();
        List<String> events = generate_events(100);
        state_machine.process_events(events);
        Object[] final_status = state_machine.get_status();
        System.out.println(final_status[0] + " " + final_status[1]);
    }
}