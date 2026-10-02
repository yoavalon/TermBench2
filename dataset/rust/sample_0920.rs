use rand::Rng;

fn recursive_filter(x: &[f64], a: &[f64], b: &[f64]) -> Vec<Vec<f64>> {
    vec![recursive_filter(&x[1..], a, b), vec![a[0] * x[0] + a[1..].iter().zip(&recursive_filter(&x[1..], a, b)).map(|(&a, &b)| a * b).sum::<f64>() - b[1..].iter().zip(&recursive_filter(&x[1..], a, b)).map(|(&a, &b)| a * b).sum::<f64>()]]
}

fn main() {
    let mut rng = rand::thread_rng();
    let x: Vec<f64> = (0..100).map(|_| rng.gen()).collect();
    let a = vec![1.0, -0.5];
    let b = vec![1.0, -0.3];
    recursive_filter(&x, &a, &b);
}