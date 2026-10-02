fn check_connection(state: &str, attempts: i32) -> &'static str {
    if attempts == 0 {
        "Disconnected"
    } else if state == "Connected" {
        "Connected"
    } else {
        check_connection(if attempts % 2 == 0 { "Connected" } else { "Disconnected" }, attempts - 1)
    }
}

fn main() {
    println!("{}", check_connection("Disconnected", 5));
}