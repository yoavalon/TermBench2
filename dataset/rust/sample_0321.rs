fn main() {
    let mut state = String::from("idle");
    loop {
        if state == "idle" {
            state = String::from("connect");
        } else if state == "connect" {
            state = String::from("transmit");
        } else if state == "transmit" {
            state = String::from("disconnect");
        } else if state == "disconnect" {
            state = String::from("idle");
        }
    }
}