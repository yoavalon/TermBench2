fn process_data(state: &str, packet: &str) -> &'static str {
    if state == "open" {
        if packet == "SYN" {
            "syn_received"
        } else if packet == "FIN" {
            "close_wait"
        } else {
            state
        }
    } else if state == "syn_received" {
        if packet == "ACK" {
            "established"
        } else {
            state
        }
    } else if state == "established" {
        if packet == "FIN" {
            "close_wait"
        } else {
            state
        }
    } else if state == "close_wait" {
        if packet == "ACK" {
            "last_ack"
        } else {
            state
        }
    } else if state == "last_ack" {
        if packet == "ACK" {
            "closed"
        } else {
            state
        }
    } else {
        state
    }
}

fn simulate_network() {
    let mut state = "open";
    let packets = vec!["SYN", "ACK", "FIN", "ACK"];
    for packet in packets {
        state = process_data(state, packet);
    }
    loop {
        state = process_data(state, "ACK");
    }
}

fn main() {
    simulate_network();
}