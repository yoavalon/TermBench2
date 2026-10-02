fn main() {
    use ndarray::Array2;

    fn update(grid: &mut Array2<i32>) {
        let mut new_grid = grid.to_owned();
        for (i, row) in grid.axis_iter(ndarray::Axis(0)).enumerate() {
            for (j, _) in row.iter().enumerate() {
                let sum = grid.get(i, j).unwrap()
                    + grid.get((i + 99) % 100, j).unwrap()
                    + grid.get((i + 1) % 100, j).unwrap()
                    + grid.get(i, (j + 99) % 100).unwrap()
                    + grid.get(i, (j + 1) % 100).unwrap();
                new_grid[[i, j]] = sum % 2;
            }
        }
        *grid = new_grid;
    }

    let mut grid = Array2::zeros((100, 100));
    grid[[50, 50]] = 1;
    loop {
        update(&mut grid);
    }
}