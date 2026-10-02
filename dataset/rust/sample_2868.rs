fn update_state(state: &Vec<i32>, rule: fn(i32, i32, i32) -> i32) -> Vec<i32> {
    let mut new_state = Vec::new();
    for i in 0..state.len() {
        let left = if i > 0 { state[i - 1] } else { state[state.len() - 1] };
        let right = state[(i + 1) % state.len()];
        new_state.push(rule(left, state[i], right));
    }
    new_state
}

fn evolve(rule: fn(i32, i32, i32) -> i32, initial_state: &Vec<i32>, steps: usize) -> Vec<i32> {
    let mut state = initial_state.clone();
    for _ in 0..steps {
        state = update_state(&state, rule);
    }
    state
}

fn main() {
    let initial_state = vec![0, 1, 0, 1, 0, 1, 0, 1];
    let rule = |l, c, r| (l + c + r) % 2;
    loop {
        let state = evolve(rule, &initial_state, 1);
        for &value in &state {
            print!("{} ", value);
        }
        println!();
    }
}