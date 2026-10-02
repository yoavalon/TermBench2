fn state_machine(state: &str, data: &str, counter: i32) -> String {
    if counter > 0 {
        let (new_state, new_data) = match state {
            "open" => ("established", format!("{}1", data)),
            "established" => ("closed", format!("{}0", data)),
            _ => ("idle", format!("{}2", data)),
        };
        state_machine(new_state, &new_data, counter - 1)
    } else {
        data.to_string()
    }
}

fn main() {
    let initial_state = "open";
    let initial_data = "";
    let max_iterations = 5;
    let result = state_machine(initial_state, initial_data, max_iterations);
    println!("{}", result);
}