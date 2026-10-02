fn state_machine(data: Vec<i32>) -> String {
    let states = vec![("A", "B"), ("B", "C"), ("C", "A")].into_iter().collect::<std::collections::HashMap<_, _>>();
    let mut current_state = "A".to_string();
    for item in data {
        current_state = states.get(&current_state).unwrap_or(&current_state).to_string();
        if current_state == "C" {
            break;
        }
    }
    current_state
}

fn main() {
    let data = vec![1, 2, 3];
    println!("{}", state_machine(data));
}