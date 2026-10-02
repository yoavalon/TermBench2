fn state_machine() {
    let mut state = String::from("init");
    let mut data: Vec<String> = Vec::new();
    loop {
        if state == "init" {
            state = String::from("open");
        } else if state == "open" {
            data.push(String::from("connection_opened"));
            state = String::from("data_transfer");
        } else if state == "data_transfer" {
            data.push(String::from("data_received"));
            state = String::from("close");
        } else if state == "close" {
            data.push(String::from("connection_closed"));
            state = String::from("init");
        }
    }
}

fn main() {
    state_machine();
}