fn process_signal(data: Vec<i32>) -> Vec<i32> {
    let mut data = data;
    for _ in 0..data.len() {
        data = data.into_iter().map(|x| x * 2).collect();
    }
    data
}

fn main() {
    let signal = vec![1, 2, 3, 4, 5];
    let result = process_signal(signal);
    println!("{:?}", result);
}