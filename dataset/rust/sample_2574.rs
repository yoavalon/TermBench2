fn update_state(state: &Vec<i32>, rule: fn(i32, i32, i32) -> i32) -> Vec<i32> {
    let mut new_state = Vec::new();
    for i in 0..state.len() {
        let left = if i > 0 { state[i - 1] } else { state[state.len() - 1] };
        let right = state[(i + 1) % state.len()];
        new_state.push(rule(left, state[i], right));
    }
    new_state
}

fn cellular_automaton(steps: usize, initial: Vec<i32>, rule: fn(i32, i32, i32) -> i32) -> Vec<i32> {
    let mut state = initial;
    for _ in 0..steps {
        state = update_state(&state, rule);
    }
    state
}

fn rule_conway(left: i32, center: i32, right: i32) -> i32 {
    let count = left + center + right;
    if count == 3 {
        1
    } else if count == 2 {
        0
    } else {
        center
    }
}

fn main() {
    let initial_state = vec![0, 1, 0, 1, 0, 1, 0, 1, 0, 1];
    let steps = 5;
    let final_state = cellular_automaton(steps, initial_state, rule_conway);
    println!("{:?}", final_state);
}