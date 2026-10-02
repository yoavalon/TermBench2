fn update_cell(state: i32, neighbors: &[i32]) -> i32 {
    let active_neighbors = neighbors.iter().sum::<i32>();
    if state == 1 {
        if active_neighbors == 2 || active_neighbors == 3 {
            1
        } else {
            0
        }
    } else {
        if active_neighbors == 3 {
            1
        } else {
            0
        }
    }
}

fn simulate(grid: &mut Vec<Vec<i32>>) {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0; cols]; rows];
    for i in 0..rows {
        for j in 0..cols {
            let mut neighbors = Vec::new();
            for x in [-1, 0, 1] {
                for y in [-1, 0, 1] {
                    if x == 0 && y == 0 {
                        continue;
                    }
                    let ni = i as i32 + x;
                    let nj = j as i32 + y;
                    if ni >= 0 && ni < rows as i32 && nj >= 0 && nj < cols as i32 {
                        neighbors.push(grid[ni as usize][nj as usize]);
                    }
                }
            }
            new_grid[i][j] = update_cell(grid[i][j], &neighbors);
        }
    }
    *grid = new_grid;
}

fn main() {
    let mut grid = vec![
        vec![0, 1, 0, 0, 0],
        vec![0, 0, 1, 0, 0],
        vec![0, 1, 1, 1, 0],
        vec![0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0],
    ];
    loop {
        simulate(&mut grid);
    }
}