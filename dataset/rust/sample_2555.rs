fn update_state(state: i32, delta: i32) -> i32 {
    state + delta
}

fn compute_sequence(steps: i32, initial: i32, increment: i32) -> Vec<i32> {
    let mut result = Vec::new();
    let mut current = initial;
    for _ in 0..steps {
        result.push(current);
        current = update_state(current, increment);
    }
    result
}

fn main() {
    let steps = 10;
    let initial = 0;
    let increment = 1;
    let sequence = compute_sequence(steps, initial, increment);
    println!("{:?}", sequence);
}