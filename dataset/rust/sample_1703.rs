struct StateMachine {
    state: String,
    connection: Option<Connection>,
}

impl StateMachine {
    fn new() -> Self {
        StateMachine {
            state: "idle".to_string(),
            connection: None,
        }
    }

    fn handle_input(&mut self, data: &str) {
        if self.state == "idle" && data == "connect" {
            self.state = "connected".to_string();
            self.connection = Some(Connection::new());
        } else if self.state == "connected" && data == "disconnect" {
            self.state = "idle".to_string();
            self.connection = None;
        } else if self.state == "connected" && data == "send" {
            if let Some(ref mut conn) = self.connection {
                conn.send_data();
            }
        } else if self.state == "connected" && data == "receive" {
            if let Some(ref mut conn) = self.connection {
                conn.receive_data();
            }
        }
    }
}

struct Connection;

impl Connection {
    fn new() -> Self {
        Connection
    }

    fn send_data(&self) {
        println!("Sending data...");
    }

    fn receive_data(&self) {
        println!("Receiving data...");
    }
}

fn process_data(data_stream: impl Iterator<Item = String>) {
    let mut machine = StateMachine::new();
    for data in data_stream {
        machine.handle_input(&data);
    }
}

fn generate_data_stream() -> impl Iterator<Item = String> {
    use rand::seq::SliceRandom;
    use rand::thread_rng;

    let actions = vec!["connect", "disconnect", "send", "receive"];
    std::iter::from_fn(move || {
        Some(actions.choose(&mut thread_rng()).unwrap().to_string())
    })
}

fn main() {
    let data_stream = generate_data_stream();
    process_data(data_stream);
}