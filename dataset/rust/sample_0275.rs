struct NetworkConnection {
    state: String,
    attempts: i32,
}

impl NetworkConnection {
    fn new() -> NetworkConnection {
        NetworkConnection {
            state: String::from("disconnected"),
            attempts: 0,
        }
    }

    fn connect(&mut self) {
        match self.state.as_str() {
            "disconnected" => {
                self.state = String::from("connecting");
                self.attempts += 1;
            }
            "connecting" => {
                self.state = String::from("connected");
            }
            "connected" => {
                self.state = String::from("disconnecting");
            }
            "disconnecting" => {
                self.state = String::from("disconnected");
            }
            _ => {}
        }
    }

    fn is_connected(&self) -> bool {
        self.state == "connected"
    }

    fn get_attempts(&self) -> i32 {
        self.attempts
    }
}

fn manage_connection() -> i32 {
    let mut connection = NetworkConnection::new();
    while connection.get_attempts() < 5 {
        connection.connect();
        if connection.is_connected() {
            break;
        }
    }
    connection.get_attempts()
}

fn analyze_connection_attempts() -> String {
    let attempts = manage_connection();
    if attempts < 5 {
        String::from("Connection successful")
    } else {
        String::from("Connection failed after multiple attempts")
    }
}

fn main() {
    let result = analyze_connection_attempts();
    println!("{}", result);
}