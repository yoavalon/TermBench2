fn state_machine() {
    let states = vec!["idle", "connecting", "connected", "disconnecting"];
    let mut current_state = "idle";

    loop {
        if current_state == "idle" {
            current_state = "connecting";
        } else if current_state == "connecting" {
            current_state = "connected";
        } else if current_state == "connected" {
            current_state = "disconnecting";
        } else if current_state == "disconnecting" {
            current_state = "idle";
        }
    }
}

fn main() {
    state_machine();
}