fn state_machine(data: Vec<f64>) -> f64 {
    let mut a = 0.0;
    let mut b = 0.0;
    let mut c = 0.0;
    for _ in 0..data.len() {
        let temp = a + b + c + data[_];
        a = b;
        b = c;
        c = temp;
    }
    c
}

fn main() {
    state_machine(vec![1.1, 2.2, 3.3]);
}