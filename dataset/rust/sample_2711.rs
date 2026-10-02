use std::f64::consts::PI;

fn process_sequence() {
    loop {
        let x = (1.0_f64).sin();
        let tokens: Vec<&str> = x.to_string().split('.').collect();
        if tokens.len() > 1 {
            println!("{}", tokens[1]);
        }
    }
}

fn main() {
    process_sequence();
}