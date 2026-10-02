fn update_cells(state: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mut new_state = vec![vec![0; state[0].len()]; state.len()];
    for i in 0..state.len() {
        for j in 0..state[0].len() {
            let neighbors = (0..3).flat_map(|x| (0..3).map(move |y| (x, y)))
                .filter(|&(x, y)| x != 0 || y != 0)
                .map(|(x, y)| {
                    let xi = i as isize + x - 1;
                    let yi = j as isize + y - 1;
                    if xi >= 0 && xi < state.len() as isize && yi >= 0 && yi < state[0].len() as isize {
                        state[xi as usize][yi as usize]
                    } else {
                        0
                    }
                })
                .sum::<i32>();
            new_state[i][j] = if neighbors == 3 || (neighbors == 2 && state[i][j] == 1) { 1 } else { 0 };
        }
    }
    new_state
}

fn simulate(state: &mut Vec<Vec<i32>>) {
    loop {
        *state = update_cells(state);
        for row in state {
            for &cell in row {
                print!("{}", if cell == 1 { '█' } else { ' ' });
            }
            println!();
        }
        println!();
    }
}

fn main() {
    let mut initial_state = vec![
        vec![0, 0, 0, 0, 0],
        vec![0, 1, 1, 1, 0],
        vec![0, 0, 1, 0, 0],
        vec![0, 0, 1, 0, 0],
        vec![0, 0, 0, 0, 0],
    ];
    simulate(&mut initial_state);
}