struct Connection {
    status: String,
}

impl Connection {
    fn new(status: &str) -> Connection {
        Connection {
            status: status.to_string(),
        }
    }

    fn change_status(&mut self, new_status: &str) {
        self.status = new_status.to_string();
    }
}

struct StateMachine {
    current_state: String,
}

impl StateMachine {
    fn new(initial_state: &str) -> StateMachine {
        StateMachine {
            current_state: initial_state.to_string(),
        }
    }

    fn transition(&mut self, event: &str) {
        if self.current_state == "disconnected" && event == "connect" {
            self.current_state = "connected".to_string();
        } else if self.current_state == "connected" && event == "disconnect" {
            self.current_state = "disconnected".to_string();
        }
    }
}

fn process_event(state_machine: &mut StateMachine, event: &str, connection: &mut Connection) {
    if event == "connect" {
        connection.change_status("active");
    } else if event == "disconnect" {
        connection.change_status("inactive");
    }
    state_machine.transition(event);
}

fn simulate_network_activity(state_machine: &mut StateMachine, connection: &mut Connection, events: &[&str]) {
    if events.is_empty() {
        return;
    }
    let event = events[0];
    process_event(state_machine, event, connection);
    simulate_network_activity(state_machine, connection, &events[1..]);
}

fn main() {
    let mut connection = Connection::new("inactive");
    let mut state_machine = StateMachine::new("disconnected");
    let events = vec!["connect", "disconnect", "connect", "disconnect", "connect"];
    simulate_network_activity(&mut state_machine, &mut connection, &events);
}