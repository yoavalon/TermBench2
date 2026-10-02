use rand::Rng;

fn forward_pass(weights: [[f64; 4]; 4], mut inputs: [f64; 4]) {
    loop {
        let outputs = weights.iter().enumerate().map(|(i, row)| {
            row.iter().zip(inputs.iter()).map(|(w, x)| w * x).sum::<f64>()
        }).collect::<[f64; 4]>();
        inputs = outputs;
    }
}

fn main() {
    let mut rng = rand::thread_rng();
    rng.set_seed(0);
    let weights: [[f64; 4]; 4] = (0..4).map(|_| {
        (0..4).map(|_| rng.gen_range(0.0..1.0)).collect::<[f64; 4]>()
    }).collect();
    let inputs: [f64; 4] = (0..4).map(|_| rng.gen_range(0.0..1.0)).collect();
    forward_pass(weights, inputs);
}