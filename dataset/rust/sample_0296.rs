use ndarray::{Array2, arr2};

struct Grid {
    grid: Array2<i32>,
    size: usize,
}

impl Grid {
    fn new(size: usize) -> Self {
        Grid {
            grid: Array2::zeros((size, size)),
            size,
        }
    }

    fn update(&mut self) {
        let mut new_grid = self.grid.clone();
        for i in 1..self.size - 1 {
            for j in 1..self.size - 1 {
                let neighbors = self.grid.slice(s![i - 1..=i + 1, j - 1..=j + 1]).to_vec();
                new_grid[[i, j]] = self.rules(&neighbors);
            }
        }
        self.grid = new_grid;
    }

    fn rules(&self, neighbors: &[i32]) -> i32 {
        let count = neighbors.iter().sum::<i32>() - self.grid[[1, 1]];
        if self.grid[[1, 1]] == 1 && (count < 2 || count > 3) {
            0
        } else if self.grid[[1, 1]] == 0 && count == 3 {
            1
        } else {
            self.grid[[1, 1]]
        }
    }
}

struct BoundaryHandler;

impl BoundaryHandler {
    fn apply(&self, grid: &mut Grid) {
        grid.grid.row_mut(0).assign(&grid.grid.row(grid.size - 2));
        grid.grid.row_mut(grid.size - 1).assign(&grid.grid.row(1));
        grid.grid.column_mut(0).assign(&grid.grid.column(grid.size - 2));
        grid.grid.column_mut(grid.size - 1).assign(&grid.grid.column(1));
    }
}

struct Simulator {
    grid: Grid,
    boundary_handler: BoundaryHandler,
    iterations: usize,
}

impl Simulator {
    fn new(grid: Grid, boundary_handler: BoundaryHandler, iterations: usize) -> Self {
        Simulator {
            grid,
            boundary_handler,
            iterations,
        }
    }

    fn run(&mut self) {
        for _ in 0..self.iterations {
            self.grid.update();
            self.boundary_handler.apply(&mut self.grid);
        }
    }
}

fn main() {
    let size = 10;
    let iterations = 50;
    let grid = Grid::new(size);
    let boundary_handler = BoundaryHandler;
    let mut simulator = Simulator::new(grid, boundary_handler, iterations);
    simulator.run();
    println!("{:?}", simulator.grid.grid);
}