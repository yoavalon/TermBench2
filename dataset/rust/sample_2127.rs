fn cellular_automata(n: usize) {
    let mut grid = vec![vec![0; n]; n];
    loop {
        let mut next_grid = vec![vec![0; n]; n];
        for i in 0..n {
            for j in 0..n {
                let neighbors = (-1..=1)
                    .flat_map(|x| (-1..=1).map(move |y| (x, y)))
                    .filter(|&(x, y)| (x, y) != (0, 0))
                    .map(|(x, y)| grid[(i + x) % n][(j + y) % n])
                    .sum::<usize>();
                if neighbors == 3 || (grid[i][j] == 1 && neighbors == 2) {
                    next_grid[i][j] = 1;
                }
            }
        }
        grid = next_grid;
    }
}

fn main() {
    cellular_automata(10);
}