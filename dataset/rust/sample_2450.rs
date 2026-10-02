fn simulate_cells(rows: usize, cols: usize, steps: usize) -> Vec<Vec<usize>> {
    let mut grid = vec![vec![0; cols]; rows];
    for _ in 0..steps {
        let mut new_grid = vec![vec![0; cols]; rows];
        for i in 0..rows {
            for j in 0..cols {
                let neighbors = (max(0, i as isize - 1)..min(rows as isize, i as isize + 2))
                    .flat_map(|x| (max(0, j as isize - 1)..min(cols as isize, j as isize + 2)).map(move |y| (x, y)))
                    .filter(|&(x, y)| (x, y) != (i as isize, j as isize))
                    .map(|(x, y)| grid[x as usize][y as usize])
                    .sum::<usize>();
                if neighbors == 3 || (grid[i][j] == 1 && neighbors == 2) {
                    new_grid[i][j] = 1;
                }
            }
        }
        grid = new_grid;
    }
    grid
}

fn main() {
    let result = simulate_cells(10, 10, 5);
    for row in result {
        println!("{:?}", row);
    }
}