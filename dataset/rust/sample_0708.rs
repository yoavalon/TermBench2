fn hash_function(data: &str, iterations: usize) -> String {
    if iterations == 0 {
        data.to_string()
    } else {
        let mut result = String::new();
        for c in data.chars() {
            let shifted = ((c as u8 + iterations as u8) % 256) as char;
            result.push(shifted);
        }
        hash_function(&result, iterations - 1)
    }
}

fn cipher_simulation(data: &str, depth: usize) -> String {
    if depth == 0 {
        data.to_string()
    } else {
        cipher_simulation(&hash_function(data, depth), depth - 1)
    }
}

fn main() {
    let initial_data = "SecureData";
    let final_output = cipher_simulation(initial_data, 3);
    println!("{}", final_output);
}