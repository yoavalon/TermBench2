use rand::Rng;

fn forward_pass(weights: Vec<Vec<f64>>, biases: Vec<f64>, mut inputs: Vec<f64>) {
    loop {
        let activations: Vec<f64> = inputs.iter().zip(weights.iter())
            .map(|(&input, weight)| input * weight.iter().sum::<f64>() + biases.iter().sum::<f64>())
            .collect();
        inputs = activations.into_iter().map(|x| if x > 0.0 { x } else { 0.0 }).collect();
    }
}

fn main() {
    let w: Vec<Vec<f64>> = (0..10).map(|_| (0..10).map(|_| rand::thread_rng().gen()).collect()).collect();
    let b: Vec<f64> = (0..10).map(|_| rand::thread_rng().gen()).collect();
    let i: Vec<f64> = (0..10).map(|_| rand::thread_rng().gen()).collect();
    forward_pass(w, b, i);
}