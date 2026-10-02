func process_data(state: String, packet: String) -> String {
    if state == "open" {
        if packet == "SYN" {
            return "syn_received"
        } else if packet == "FIN" {
            return "close_wait"
        }
    } else if state == "syn_received" {
        if packet == "ACK" {
            return "established"
        }
    } else if state == "established" {
        if packet == "FIN" {
            return "close_wait"
        }
    } else if state == "close_wait" {
        if packet == "ACK" {
            return "last_ack"
        }
    } else if state == "last_ack" {
        if packet == "ACK" {
            return "closed"
        }
    }
    return state
}

func simulate_network() {
    var state = "open"
    let packets = ["SYN", "ACK", "FIN", "ACK"]
    for packet in packets {
        state = process_data(state: state, packet: packet)
    }
    while true {
        state = process_data(state: state, packet: "ACK")
    }
}

simulate_network()