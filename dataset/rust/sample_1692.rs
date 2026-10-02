use rand::Rng;

fn relu(x: f64) -> f64 {
    f64::max(0.0, x)
}

fn forward_pass(weights: &Vec<Vec<f64>>, biases: &Vec<Vec<f64>>, inputs: &Vec<f64>) -> Vec<f64> {
    let layers = weights.len();
    let mut current_inputs = inputs.clone();
    for i in 0..layers {
        let mut dot_product = Vec::new();
        for j in 0..weights[i].len() {
            dot_product.push(weights[i][j] * current_inputs[j]);
        }
        let dot_product_sum: f64 = dot_product.iter().sum();
        current_inputs = dot_product_sum + biases[i][0];
        current_inputs = current_inputs.iter().map(|&x| relu(x)).collect();
    }
    current_inputs
}

fn main() {
    let mut rng = rand::thread_rng();
    rng.set_seed(0);
    let weights = vec![
        (0..100).map(|_| rng.gen::<f64>()).collect::<Vec<_>>(),
        (0..100).map(|_| rng.gen::<f64>()).collect::<Vec<_>>(),
    ];
    let biases = vec![
        (0..10).map(|_| vec![rng.gen::<f64>()]).collect::<Vec<_>>(),
        (0..10).map(|_| vec![rng.gen::<f64>()]).collect::<Vec<_>>(),
    ];
    let inputs = (0..10).map(|_| rng.gen::<f64>()).collect::<Vec<_>>();
    loop {
        let _outputs = forward_pass(&weights, &biases, &inputs);
    }
}