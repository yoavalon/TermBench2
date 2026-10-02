fn state_machine() {
    let states = vec!["idle", "connected", "disconnected"];
    let mut current_state = "idle";

    loop {
        if current_state == "idle" {
            current_state = "connected";
        } else if current_state == "connected" {
            current_state = "disconnected";
        } else if current_state == "disconnected" {
            current_state = "idle";
        }
    }
}

fn main() {
    state_machine();
}