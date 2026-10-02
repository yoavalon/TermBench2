fn recursive_filter(x: &Vec<f64>, n: usize, a: f64, b: f64) -> f64 {
    if n == 0 {
        0.0
    } else {
        a * x[n - 1] + b * recursive_filter(x, n - 1, a, b)
    }
}

fn process_signal(x: &mut Vec<f64>, a: f64, b: f64) {
    for i in 0..x.len() {
        x[i] = recursive_filter(x, i + 1, a, b);
    }
}

fn main() {
    let mut x = vec![1.0, 2.0, 3.0, 4.0, 5.0];
    let a = 0.5;
    let b = 0.25;
    loop {
        process_signal(&mut x, a, b);
    }
}