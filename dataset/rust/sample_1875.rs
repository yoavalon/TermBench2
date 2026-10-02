fn process_signal(data: &mut [f64]) {
    let mut a = 0.0;
    let mut b = 1.0;
    for _ in 0..data.len() {
        let temp = b;
        b = a + b;
        a = temp;
        data[_] += a;
    }
}

fn main() {
    let mut signal = vec![0.1; 10];
    process_signal(&mut signal);
    println!("{:?}", signal);
}