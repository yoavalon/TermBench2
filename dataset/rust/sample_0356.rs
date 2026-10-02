fn track_sequence() {
    let mut data = vec![1];
    loop {
        let next_value = *data.last().unwrap() + 1;
        data.push(next_value);
        println!("{}", next_value);
    }
}

fn main() {
    track_sequence();
}