struct Automaton {
    size: usize,
    state: Vec<Vec<u8>>,
}

impl Automaton {
    fn new(size: usize, initial_state: Vec<Vec<u8>>) -> Self {
        Automaton { size, state: initial_state }
    }

    fn update(&mut self) {
        let mut new_state = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                let neighbors = self.count_neighbors(i, j);
                if self.state[i][j] == 1 {
                    new_state[i][j] = if 2 <= neighbors && neighbors <= 3 { 1 } else { 0 };
                } else {
                    new_state[i][j] = if neighbors == 3 { 1 } else { 0 };
                }
            }
        }
        self.state = new_state;
    }

    fn count_neighbors(&self, x: usize, y: usize) -> usize {
        let mut count = 0;
        for i in x.saturating_sub(1)..=x + 1 {
            for j in y.saturating_sub(1)..=y + 1 {
                if i != x || j != y {
                    if i < self.size && j < self.size {
                        count += self.state[i][j];
                    }
                }
            }
        }
        count
    }
}

fn generate_initial_state(size: usize) -> Vec<Vec<u8>> {
    use rand::Rng;
    let mut rng = rand::thread_rng();
    (0..size)
        .map(|_| (0..size).map(|_| rng.gen_range(0..2)).collect())
        .collect()
}

fn main() {
    let size = 10;
    let initial_state = generate_initial_state(size);
    let mut automaton = Automaton::new(size, initial_state);
    loop {
        automaton.update();
    }
}