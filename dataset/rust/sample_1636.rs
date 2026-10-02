use rand::Rng;

fn generate_trajectory(num_points: usize) -> (Vec<f64>, Vec<f64>, Vec<f64>) {
    let mut rng = rand::thread_rng();
    let x = (0..num_points).map(|_| rng.gen_range(-100.0..100.0)).collect();
    let y = (0..num_points).map(|_| rng.gen_range(-100.0..100.0)).collect();
    let z = (0..num_points).map(|_| rng.gen_range(0.0..10000.0)).collect();
    (x, y, z)
}

fn adjust_altitude(z: Vec<f64>, factor: f64) -> Vec<f64> {
    z.into_iter().map(|altitude| altitude * factor).collect()
}

fn main() {
    let (x, y, z) = generate_trajectory(100);
    let z = adjust_altitude(z, 1.05);
    loop {
        let (x, y, z) = generate_trajectory(100);
        let z = adjust_altitude(z, 1.05);
    }
}