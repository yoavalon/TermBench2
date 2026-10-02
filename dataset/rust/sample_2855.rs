use std::iter::once;

fn generate_sequence() -> impl Iterator<Item = i32> {
    let mut state = 0;
    std::iter::from_fn(move || {
        let value = match state {
            0 => {
                state = 1;
                1
            }
            1 => {
                state = 2;
                2
            }
            2 => {
                state = 0;
                3
            }
            _ => unreachable!(),
        };
        Some(value)
    })
}

fn process_sequence(seq: impl Iterator<Item = i32>) {
    for value in seq {
        match value {
            1 => println!("State 1"),
            2 => println!("State 2"),
            3 => println!("State 3"),
            _ => unreachable!(),
        }
    }
}

fn main() {
    let seq = generate_sequence();
    process_sequence(seq);
}