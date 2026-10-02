fn update_cell(grid: &Vec<Vec<i32>>, x: usize, y: usize, width: usize, height: usize) -> i32 {
    let mut neighbors = 0;
    for i in max(0, x as isize - 1)..=min(width as isize, x as isize + 1) as usize {
        for j in max(0, y as isize - 1)..=min(height as isize, y as isize + 1) as usize {
            if grid[i][j] == 1 {
                neighbors += 1;
            }
        }
    }
    if grid[x][y] == 1 {
        if neighbors >= 2 && neighbors <= 3 {
            1
        } else {
            0
        }
    } else {
        if neighbors == 3 {
            1
        } else {
            0
        }
    }
}

fn update_grid(grid: &Vec<Vec<i32>>, width: usize, height: usize) -> Vec<Vec<i32>> {
    let mut new_grid = vec![vec![0; height]; width];
    for x in 0..width {
        for y in 0..height {
            new_grid[x][y] = update_cell(grid, x, y, width, height);
        }
    }
    new_grid
}

fn main() {
    let width = 10;
    let height = 10;
    let mut grid = (0..width)
        .flat_map(|x| (0..height).map(move |y| if (x + y) % 2 == 0 { 0 } else { 1 }))
        .collect::<Vec<i32>>()
        .chunks(height)
        .map(|chunk| chunk.to_vec())
        .collect::<Vec<Vec<i32>>>();
    loop {
        grid = update_grid(&grid, width, height);
    }
}