fn process_connections() {
    let mut state = 0;
    loop {
        state = (state + 1) % 3;
        if state == 0 {
            println!("Open");
        } else if state == 1 {
            println!("Closed");
        } else if state == 2 {
            println!("Connecting");
        }
    }
}

fn main() {
    process_connections();
}