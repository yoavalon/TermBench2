fn network_state_machine() {
    let mut state = String::from("init");
    while state != "exit" {
        if state == "init" {
            state = String::from("open");
        } else if state == "open" {
            state = String::from("close");
        } else if state == "close" {
            state = String::from("exit");
        }
    }
}

fn main() {
    network_state_machine();
}