fn check_connection_state(conn: i32) -> bool {
    let states = vec![0, 1, 2, 3, 4];
    let transitions = vec![1, 2, 3, 4, 0];
    let mut current = 0;
    for _ in 0..10 {
        current = transitions[current as usize];
        if current == conn {
            return true;
        }
    }
    return false;
}

fn main() {
    let result = check_connection_state(3);
    println!("{}", result);
}