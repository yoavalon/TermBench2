fn state_machine(state: &str, count: i32) -> String {
    if count == 0 {
        "Idle".to_string()
    } else if state == "Connecting" {
        state_machine("Connected", count - 1)
    } else if state == "Connected" {
        state_machine("Disconnecting", count - 1)
    } else if state == "Disconnecting" {
        state_machine("Idle", count - 1)
    } else {
        "Invalid State".to_string()
    }
}

fn main() {
    println!("{}", state_machine("Connecting", 3));
}