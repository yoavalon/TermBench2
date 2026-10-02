fn update_grid(grid: &Vec<i32>, rule: fn(i32, i32, i32) -> i32) -> Vec<i32> {
    let size = grid.len();
    let mut new_grid = vec![0; size];
    for i in 0..size {
        let left = grid[(i + size - 1) % size];
        let right = grid[(i + 1) % size];
        new_grid[i] = rule(left, grid[i], right);
    }
    new_grid
}

fn cellular_automaton(steps: i32, initial_state: Vec<i32>, rule: fn(i32, i32, i32) -> i32) -> Vec<i32> {
    let mut current_state = initial_state;
    for _ in 0..steps {
        current_state = update_grid(&current_state, rule);
    }
    current_state
}

fn rule_conway(left: i32, center: i32, right: i32) -> i32 {
    let neighbor_count = left + center + right;
    if center == 1 {
        if neighbor_count == 2 || neighbor_count == 3 {
            1
        } else {
            0
        }
    } else {
        if neighbor_count == 3 {
            1
        } else {
            0
        }
    }
}

fn main() {
    let initial_state = vec![0, 1, 0, 1, 1, 0, 1, 0];
    let steps = 5;
    let final_state = cellular_automaton(steps, initial_state, rule_conway);
    println!("{:?}", final_state);
}