struct NetworkConnection {
    state: String,
}

impl NetworkConnection {
    fn new() -> NetworkConnection {
        NetworkConnection {
            state: String::from("disconnected"),
        }
    }

    fn connect(&mut self) -> bool {
        if self.state == "disconnected" {
            self.state = String::from("connected");
            true
        } else {
            false
        }
    }

    fn disconnect(&mut self) -> bool {
        if self.state == "connected" {
            self.state = String::from("disconnected");
            true
        } else {
            false
        }
    }

    fn is_connected(&self) -> bool {
        self.state == "connected"
    }
}

fn monitor_connection(conn: &mut NetworkConnection) {
    loop {
        if conn.is_connected() {
            println!("Connection is active.");
        } else {
            println!("No active connection.");
            conn.connect();
        }
    }
}

fn main() {
    let mut conn = NetworkConnection::new();
    monitor_connection(&mut conn);
}