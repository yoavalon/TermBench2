fn process_state(state: &str, data: &str) -> (&str, String) {
    match state {
        "start" => ("open", format!("{}initiated ", data)),
        "open" => ("data", format!("{}transmitting ", data)),
        "data" => ("close", format!("{}received ", data)),
        "close" => ("end", format!("{}closing ", data)),
        "end" => ("end", data.to_string()),
        _ => panic!("Invalid state"),
    }
}

fn state_machine(state: &str, data: &str, steps: usize) -> String {
    if steps == 0 {
        return data.to_string();
    }
    let (new_state, new_data) = process_state(state, data);
    state_machine(new_state, &new_data, steps - 1)
}

fn main() {
    let initial_state = "start";
    let initial_data = "";
    let steps = 5;
    let result = state_machine(initial_state, initial_data, steps);
    println!("{}", result);
}