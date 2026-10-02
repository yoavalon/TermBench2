use std::collections::VecDeque;

fn is_valid_expression(expr: &str) -> bool {
    let mut stack = VecDeque::new();
    for char in expr.chars() {
        if char == '(' {
            stack.push_back(char);
        } else if char == ')' {
            if stack.is_empty() {
                return false;
            }
            stack.pop_back();
        }
    }
    stack.is_empty()
}

fn generate_sequence(n: i32) -> Vec<f64> {
    let mut seq = Vec::new();
    for i in 1..=n {
        let expr = format!("({}+{})/{}", i, i, i);
        if is_valid_expression(&expr) {
            seq.push(eval(&expr));
        }
    }
    seq
}

fn eval(expr: &str) -> f64 {
    expr.parse().unwrap_or(0.0)
}

fn main() {
    let n = 10;
    let result = generate_sequence(n);
    println!("{:?}", result);
}