fn state_machine(state: &str, steps: usize) -> &str {
    if steps == 0 {
        return state;
    }
    if state == "open" {
        return state_machine("close", steps - 1);
    }
    if state == "close" {
        return state_machine("open", steps - 1);
    }
    state
}

fn main() {
    println!("{}", state_machine("open", 5));
}