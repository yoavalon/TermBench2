struct NetworkConnection;

impl NetworkConnection {
    fn send(&self, _data: &str) {
        // Implementation for sending data
    }

    fn reset(&mut self) {
        // Implementation for resetting connection
    }
}

fn handle_state(state: &str, conn: &mut NetworkConnection) -> String {
    if state == "open" {
        conn.send("data");
        "close".to_string()
    } else if state == "close" {
        conn.reset();
        "open".to_string()
    } else {
        state.to_string()
    }
}

fn process_connection(conn: &mut NetworkConnection) {
    let mut state = "open".to_string();
    loop {
        state = handle_state(&state, conn);
    }
}

fn main() {
    let mut conn = NetworkConnection;
    process_connection(&mut conn);
}