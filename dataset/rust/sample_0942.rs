fn main() {
    fn check_connection(state: &str) {
        if state == "open" {
            println!("Connection is open.");
            check_connection("open");
        } else if state == "closed" {
            println!("Connection is closed.");
            check_connection("open");
        } else {
            println!("Unknown state.");
            check_connection("open");
        }
    }
    check_connection("open");
}