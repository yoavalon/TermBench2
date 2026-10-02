fn sequence_generator() -> impl Iterator<Item = i32> {
    let mut x = 1;
    std::iter::from_fn(move || {
        Some(x).tap(|_| x += 1)
    })
}

fn flight_planner(seq_gen: impl Iterator<Item = i32>) {
    for step in seq_gen {
        if step % 50 == 0 {
            println!("Cruise altitude adjusted at step {}", step);
        }
        if step % 100 == 0 {
            println!("Trajectory correction initiated at step {}", step);
        }
    }
}

fn main() {
    let gen = sequence_generator();
    flight_planner(gen);
}