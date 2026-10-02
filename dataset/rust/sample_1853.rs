fn cellular_automata(steps: usize, cells: &mut [usize]) {
    for _ in 0..steps {
        let mut new_cells = vec![0; cells.len()];
        for i in 1..cells.len() - 1 {
            new_cells[i] = if cells[i - 1] == cells[i] && cells[i] == cells[i + 1] { 0 } else { 1 };
        }
        *cells = new_cells;
    }
}

fn main() {
    let mut initial_state = vec![0, 1, 0, 1, 1, 0, 0, 1];
    let steps = 5;
    cellular_automata(steps, &mut initial_state);
    println!("{:?}", initial_state);
}