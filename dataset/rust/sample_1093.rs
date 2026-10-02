fn update_state(grid: &mut Vec<Vec<i32>>, x: usize, y: usize, size: usize) -> &mut Vec<Vec<i32>> {
    if x >= size || y >= size {
        return grid;
    }
    let mut neighbors = 0;
    for i in -1..2 {
        for j in -1..2 {
            if i == 0 && j == 0 {
                continue;
            }
            let nx = x as i32 + i;
            let ny = y as i32 + j;
            if nx >= 0 && nx < size as i32 && ny >= 0 && ny < size as i32 {
                neighbors += grid[nx as usize][ny as usize];
            }
        }
    }
    if grid[x][y] == 1 {
        if neighbors < 2 || neighbors > 3 {
            grid[x][y] = 0;
        }
    } else if neighbors == 3 {
        grid[x][y] = 1;
    }
    if x < size - 1 {
        update_state(grid, x + 1, y, size)
    } else if y < size - 1 {
        update_state(grid, 0, y + 1, size)
    } else {
        grid
    }
}

fn main() {
    let size = 10;
    let mut grid = vec![vec![0; size]; size];
    grid[size / 2][size / 2] = 1;
    loop {
        update_state(&mut grid, 0, 0, size);
    }
}