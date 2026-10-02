use rand::Rng;

struct Grid {
    size: usize,
    state: Vec<Vec<usize>>,
}

impl Grid {
    fn new(size: usize, initial_state: Vec<Vec<usize>>) -> Grid {
        Grid { size, state: initial_state }
    }

    fn update(&mut self) {
        let mut new_state = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                let neighbors = self.count_neighbors(i, j);
                if self.state[i][j] == 1 && (neighbors == 2 || neighbors == 3) {
                    new_state[i][j] = 1;
                } else if self.state[i][j] == 0 && neighbors == 3 {
                    new_state[i][j] = 1;
                }
            }
        }
        self.state = new_state;
    }

    fn count_neighbors(&self, x: usize, y: usize) -> usize {
        let mut count = 0;
        for i in 0.max(x as isize - 1)..=self.size.min(x + 2) {
            for j in 0.max(y as isize - 1)..=self.size.min(y + 2) {
                if (i != x as isize || j != y as isize) && self.state[i as usize][j as usize] == 1 {
                    count += 1;
                }
            }
        }
        count
    }
}

fn generate_initial_state(size: usize, density: f64) -> Vec<Vec<usize>> {
    let mut rng = rand::thread_rng();
    (0..size)
        .map(|_| {
            (0..size)
                .map(|_| if rng.gen::<f64>() < density { 1 } else { 0 })
                .collect()
        })
        .collect()
}

fn main() {
    let size = 100;
    let density = 0.2;
    let mut grid = Grid::new(size, generate_initial_state(size, density));
    loop {
        grid.update();
    }
}