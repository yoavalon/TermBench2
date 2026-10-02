fn process_sequence(data: Vec<i32>, steps: i32) -> Vec<i32> {
    let mut result = data;
    for _ in 0..steps {
        result = result.into_iter().map(|x| x + 1).collect();
    }
    result
}

fn main() {
    let initial_data = vec![0, 1, 2, 3, 4];
    let steps = 5;
    let result = process_sequence(initial_data, steps);
    println!("{:?}", result);
}