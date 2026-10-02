fn state_machine(state: &str, count: usize, max_count: usize) -> &'static str {
    if count >= max_count {
        return "Terminated";
    }
    match state {
        "CONNECTING" => state_machine("OPEN", count + 1, max_count),
        "OPEN" => state_machine("CLOSING", count + 1, max_count),
        "CLOSING" => state_machine("DISCONNECTED", count + 1, max_count),
        "DISCONNECTED" => state_machine("RECONNECTING", count + 1, max_count),
        "RECONNECTING" => state_machine("CONNECTING", count + 1, max_count),
        _ => "Unknown State",
    }
}

fn main() {
    state_machine("CONNECTING", 0, 10);
}