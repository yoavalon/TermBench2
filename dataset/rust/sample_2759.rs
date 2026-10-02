extern crate ndarray;
use ndarray::{Array2, arr2, ArrayView2};

fn simulate() {
    fn update(state: &Array2<i32>) -> Array2<i32> {
        let mut new_state = state.to_owned();
        let neighbors = [
            state.roll_axis(Axis(0), 1),
            state.roll_axis(Axis(0), -1),
            state.roll_axis(Axis(1), 1),
            state.roll_axis(Axis(1), -1),
        ]
        .iter()
        .sum::<Array2<i32>>();

        for ((&s, &n), new) in state.iter().zip(neighbors.iter()).zip(new_state.iter_mut()) {
            if s == 1 && n < 2 {
                *new = 0;
            } else if s == 1 && n > 3 {
                *new = 0;
            } else if s == 0 && n == 3 {
                *new = 1;
            }
        }
        new_state
    }

    let size = (20, 20);
    let state = Array2::from_shape_fn(size, |_| rand::random::<i32>() % 2);
    let mut state = state;

    loop {
        state = update(&state);
    }
}

fn main() {
    simulate();
}