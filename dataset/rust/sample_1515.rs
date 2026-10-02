use rand::Rng;

fn simulate() {
    let mut state = vec![vec![0; 50]; 50];
    let mut rng = rand::thread_rng();

    for i in 0..50 {
        for j in 0..50 {
            state[i][j] = rng.gen_range(0..2);
        }
    }

    loop {
        let mut new_state = vec![vec![0; 50]; 50];
        for i in 1..49 {
            for j in 1..49 {
                let neighbors = state[i - 1][j - 1] + state[i - 1][j] + state[i - 1][j + 1] +
                               state[i][j - 1] + state[i][j + 1] +
                               state[i + 1][j - 1] + state[i + 1][j] + state[i + 1][j + 1];
                if state[i][j] == 1 && (neighbors == 2 || neighbors == 3) {
                    new_state[i][j] = 1;
                } else if state[i][j] == 0 && neighbors == 3 {
                    new_state[i][j] = 1;
                }
            }
        }
        state = new_state;
    }
}

fn main() {
    simulate();
}