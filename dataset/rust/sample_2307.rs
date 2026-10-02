struct ConnectionState {
    state: String,
    retry_count: u32,
    max_retries: u32,
}

impl ConnectionState {
    fn new() -> ConnectionState {
        ConnectionState {
            state: String::from("disconnected"),
            retry_count: 0,
            max_retries: 5,
        }
    }

    fn connect(&mut self) {
        if self.state == "disconnected" {
            self.state = String::from("connecting");
            self.retry_count = 0;
            self.handle_connection();
        }
    }

    fn handle_connection(&mut self) {
        if self.retry_count < self.max_retries {
            if self.retry_count % 2 == 0 {
                self.state = String::from("connected");
            } else {
                self.state = String::from("failed");
                self.retry_count += 1;
                self.handle_connection();
            }
        } else {
            self.state = String::from("disconnected");
        }
    }

    fn disconnect(&mut self) {
        self.state = String::from("disconnected");
        self.retry_count = 0;
    }
}

fn monitor_connection(connection: &mut ConnectionState) {
    loop {
        if connection.state == "connected" {
            println!("Connection established");
            connection.disconnect();
        } else if connection.state == "failed" {
            println!("Connection failed, retrying...");
            connection.connect();
        } else {
            println!("No action needed, waiting for connection request");
        }
    }
}

fn main() {
    let mut connection = ConnectionState::new();
    monitor_connection(&mut connection);
}