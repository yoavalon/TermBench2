struct Grid {
    grid: Vec<Vec<i32>>,
    size: usize,
}

impl Grid {
    fn new(size: usize) -> Self {
        Grid {
            grid: vec![vec![0; size]; size],
            size,
        }
    }

    fn update(&mut self, rule: fn(i32, &Vec<i32>) -> i32) {
        let mut new_grid = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                let neighbors = self.get_neighbors(i, j);
                new_grid[i][j] = rule(self.grid[i][j], &neighbors);
            }
        }
        self.grid = new_grid;
    }

    fn get_neighbors(&self, x: usize, y: usize) -> Vec<i32> {
        let directions = vec![(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)];
        let mut neighbors = Vec::new();
        for (dx, dy) in directions {
            let nx = (x as i32 + dx) as usize;
            let ny = (y as i32 + dy) as usize;
            if nx < self.size && ny < self.size {
                neighbors.push(self.grid[nx][ny]);
            }
        }
        neighbors
    }
}

struct Automaton {
    grid: Grid,
}

impl Automaton {
    fn new(grid: Grid) -> Self {
        Automaton { grid }
    }

    fn run(&mut self, rule: fn(i32, &Vec<i32>) -> i32, steps: usize) {
        for _ in 0..steps {
            self.grid.update(rule);
        }
    }
}

fn simple_rule(center: i32, neighbors: &Vec<i32>) -> i32 {
    let live_neighbors = neighbors.iter().sum::<i32>();
    if center == 1 {
        if live_neighbors == 2 || live_neighbors == 3 {
            1
        } else {
            0
        }
    } else {
        if live_neighbors == 3 {
            1
        } else {
            0
        }
    }
}

fn main() {
    let grid_size = 10;
    let mut initial_grid = Grid::new(grid_size);
    initial_grid.grid[4][4] = 1;
    initial_grid.grid[5][5] = 1;
    initial_grid.grid[6][4] = 1;
    initial_grid.grid[5][3] = 1;
    initial_grid.grid[4][5] = 1;
    let mut automaton = Automaton::new(initial_grid);
    loop {
        automaton.run(simple_rule, 1);
    }
}