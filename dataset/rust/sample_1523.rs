use rand::Rng;

fn simulate_thermo_state() {
    let mut a = [0.0; 10];
    let mut rng = rand::thread_rng();
    for i in 0..10 {
        a[i] = rng.gen();
    }
    loop {
        let mut b = [0.0; 10];
        for i in 0..10 {
            b[i] = rng.gen();
        }
        a = dot_product(&a, &b);
    }
}

fn dot_product(a: &[f64], b: &[f64]) -> [f64; 10] {
    let mut result = [0.0; 10];
    for i in 0..10 {
        result[i] = a.iter().zip(b.iter()).map(|(&x, &y)| x * y).sum();
    }
    result
}

fn main() {
    simulate_thermo_state();
}