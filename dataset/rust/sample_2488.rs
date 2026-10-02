fn process_signal(data: Vec<i32>) -> Vec<i32> {
    let n = data.len();
    let mut result = vec![0; n];
    for i in 0..n {
        for j in 0..=i {
            result[i] += data[j];
        }
    }
    result
}

fn main() {
    let data = vec![1, 2, 3, 4, 5];
    let output = process_signal(data);
    println!("{:?}", output);
}