fn state_machine(state: &str, count: i32) -> String {
    if state == "open" && count < 3 {
        state_machine("closed", count + 1)
    } else if state == "closed" && count < 3 {
        state_machine("open", count + 1)
    } else {
        "final".to_string()
    }
}

fn main() {
    state_machine("open", 0);
}