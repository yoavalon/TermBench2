use rand::Rng;

fn init_weights(size: usize) -> Vec<Vec<f64>> {
    let mut rng = rand::thread_rng();
    (0..size)
        .map(|_| (0..size).map(|_| rng.gen::<f64>()).collect())
        .collect()
}

fn forward_pass(input_data: &Vec<Vec<f64>>, weights: &Vec<Vec<f64>>) -> Vec<Vec<f64>> {
    let mut result = vec![vec![0.0; 1]; input_data.len()];
    for i in 0..input_data.len() {
        for j in 0..weights.len() {
            result[i][0] += input_data[i][0] * weights[i][j];
        }
    }
    result
}

fn terminate_condition(data: &Vec<Vec<f64>>) -> bool {
    data.iter().all(|&x| x[0] < 0.1)
}

fn main() {
    let size = 5;
    let weights = init_weights(size);
    let mut data: Vec<Vec<f64>> = (0..size).map(|_| vec![rand::random::<f64>()]).collect();
    loop {
        data = forward_pass(&data, &weights);
        if terminate_condition(&data) {
            break;
        }
    }
}