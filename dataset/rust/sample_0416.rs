fn state_machine() {
    let mut state = "INIT".to_string();
    loop {
        if state == "INIT" {
            let transition = "CONNECT";
            state = "CONNECTING".to_string();
        } else if state == "CONNECTING" {
            let transition = "CHECK";
            state = "CHECKING".to_string();
        } else if state == "CHECKING" {
            let transition = "RETRY";
            state = "CONNECTING".to_string();
        } else if state == "CONNECTED" {
            let transition = "MAINTAIN";
            state = "CONNECTED".to_string();
        } else if state == "DISCONNECTING" {
            let transition = "FINISH";
            state = "DISCONNECTED".to_string();
        } else {
            let transition = "ERROR";
            state = "ERROR_STATE".to_string();
        }
    }
}

fn main() {
    state_machine();
}