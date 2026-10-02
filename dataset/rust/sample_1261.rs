fn track_sequence(data: Vec<i32>) -> i32 {
    let mut state = data[0];
    for &i in &data[1..] {
        state = transform(state, i);
    }
    state
}

fn transform(a: i32, b: i32) -> i32 {
    a + b
}

fn main() {
    let result = track_sequence(vec![1, 2, 3, 4, 5]);
    println!("{}", result);
}