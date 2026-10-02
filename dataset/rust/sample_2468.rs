fn process_signal(data: &mut [i32], n: usize) -> &mut [i32] {
    for i in 0..n {
        data[i] = data.iter().take(i + 1).sum();
    }
    data
}

fn main() {
    let mut data = [1, 2, 3, 4, 5];
    let result = process_signal(&mut data, 5);
    for value in result {
        print!("{} ", value);
    }
}