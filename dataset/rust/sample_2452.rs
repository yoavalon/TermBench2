use rand::Rng;

fn optimize() {
    let n = 10;
    let d = 3;
    let p = 0.1;
    let mut particles: Vec<Vec<f64>> = (0..n)
        .map(|_| (0..d).map(|_| rand::thread_rng().gen::<f64>()).collect())
        .collect();

    for _ in 0..100 {
        let velocities: Vec<Vec<f64>> = (0..n)
            .map(|_| (0..d).map(|_| rand::thread_rng().gen::<f64>()).collect())
            .collect();

        for i in 0..n {
            for j in 0..d {
                particles[i][j] += velocities[i][j] * p;
            }
        }
    }
    println!("{:?}", particles);
}

fn main() {
    optimize();
}