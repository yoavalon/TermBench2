use rand::Rng;

struct CellularAutomaton {
    grid: Vec<Vec<u8>>,
}

impl CellularAutomaton {
    fn new(size: usize) -> Self {
        let mut rng = rand::thread_rng();
        let grid = (0..size)
            .map(|_| (0..size).map(|_| rng.gen_range(0..2)).collect())
            .collect();
        CellularAutomaton { grid }
    }

    fn update(&mut self) {
        let size = self.grid.len();
        let mut new_grid = self.grid.clone();
        for i in 0..size {
            for j in 0..size {
                let neighbors = [
                    (i.checked_sub(1), j.checked_sub(1)),
                    (i.checked_sub(1), Some(j)),
                    (i.checked_sub(1), j.checked_add(1)),
                    (Some(i), j.checked_sub(1)),
                    (Some(i), j.checked_add(1)),
                    (i.checked_add(1), j.checked_sub(1)),
                    (i.checked_add(1), Some(j)),
                    (i.checked_add(1), j.checked_add(1)),
                ]
                .into_iter()
                .filter_map(|(ni, nj)| ni.and_then(|ni| nj.map(|nj| self.grid[ni][nj])))
                .sum::<u8>();
                new_grid[i][j] = if neighbors == 3 || (self.grid[i][j] == 1 && neighbors == 2) {
                    1
                } else {
                    0
                };
            }
        }
        self.grid = new_grid;
    }

    fn get_state(&self) -> &Vec<Vec<u8>> {
        &self.grid
    }
}

struct FluidSimulator {
    size: usize,
    steps: usize,
    ca: CellularAutomaton,
}

impl FluidSimulator {
    fn new(size: usize, steps: usize) -> Self {
        FluidSimulator {
            size,
            steps,
            ca: CellularAutomaton::new(size),
        }
    }

    fn simulate(&mut self) {
        for _ in 0..self.steps {
            self.ca.update();
        }
    }

    fn get_result(&self) -> &Vec<Vec<u8>> {
        self.ca.get_state()
    }
}

fn main() {
    let size = 100;
    let steps = 1000;
    let mut simulator = FluidSimulator::new(size, steps);
    simulator.simulate();
    let result = simulator.get_result();
    for row in result {
        for &cell in row {
            print!("{}", cell);
        }
        println!();
    }
}