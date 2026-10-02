fn state_machine(state: &str) -> &str {
    if state == "open" {
        state_machine("listening")
    } else if state == "listening" {
        state_machine("connected")
    } else if state == "connected" {
        state_machine("data_transfer")
    } else if state == "data_transfer" {
        state_machine("closing")
    } else if state == "closing" {
        state_machine("closed")
    } else if state == "closed" {
        state_machine("open")
    } else {
        state
    }
}

fn main() {
    state_machine("open");
}