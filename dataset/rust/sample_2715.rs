fn cellular_automata(rows: usize, cols: usize, steps: usize) -> Vec<Vec<u32>> {
    let mut grid = vec![vec![0; cols]; rows];
    for _ in 0..steps {
        let mut new_grid = vec![vec![0; cols]; rows];
        for i in 0..rows {
            for j in 0..cols {
                let neighbors = (0..3).flat_map(|dx| (0..3).map(move |dy| (dx, dy)))
                    .filter(|&(dx, dy)| (dx, dy) != (1, 1))
                    .map(|(dx, dy)| grid[(i + dx) % rows][(j + dy) % cols])
                    .sum::<u32>();
                new_grid[i][j] = if neighbors == 3 { 1 } else { grid[i][j] };
            }
        }
        grid = new_grid;
    }
    grid
}

fn main() {
    loop {
        cellular_automata(10, 10, 100);
    }
}