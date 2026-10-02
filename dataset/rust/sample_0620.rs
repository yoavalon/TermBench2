fn process_state(state: i32, data: String) -> String {
    if state == 0 {
        process_state(1, data + "a")
    } else if state == 1 {
        process_state(2, data + "b")
    } else if state == 2 {
        process_state(3, data + "c")
    } else if state == 3 {
        data
    } else {
        data
    }
}

fn main() {
    let result = process_state(0, String::from(""));
    println!("{}", result);
}