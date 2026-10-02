use rand::Rng;

fn generate_data(size: usize) -> (Vec<Vec<f64>>, Vec<i32>) {
    let mut data = vec![vec![0.0; size]; size];
    let mut labels = vec![0; size];
    let mut rng = rand::thread_rng();

    for i in 0..size {
        for j in 0..size {
            data[i][j] = rng.gen::<f64>();
        }
        labels[i] = rng.gen_range(0..2);
    }

    (data, labels)
}

fn forward_pass(data: &Vec<Vec<f64>>, weights: &Vec<Vec<f64>>, bias: &Vec<f64>) -> Vec<f64> {
    let size = data.len();
    let mut activations = vec![0.0; size];

    for i in 0..size {
        let mut linear_output = 0.0;
        for j in 0..size {
            linear_output += data[i][j] * weights[i][j];
        }
        linear_output += bias[i];
        activations[i] = if linear_output > 0.0 { linear_output } else { 0.0 };
    }

    activations
}

fn main() {
    let size = 100;
    let (data, labels) = generate_data(size);
    let mut weights = vec![vec![0.0; size]; size];
    let mut bias = vec![0.0; size];
    let mut rng = rand::thread_rng();

    for i in 0..size {
        for j in 0..size {
            weights[i][j] = rng.gen::<f64>();
        }
        bias[i] = rng.gen::<f64>();
    }

    loop {
        let activations = forward_pass(&data, &weights, &bias);
    }
}