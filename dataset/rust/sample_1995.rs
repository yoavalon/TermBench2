use rand::Rng;

fn matrix_multiply(a: &Vec<Vec<f64>>, b: &Vec<Vec<f64>>) -> Vec<Vec<f64>> {
    let mut result = vec![vec![0.0; b[0].len()]; a.len()];
    for i in 0..a.len() {
        for j in 0..b[0].len() {
            for k in 0..b.len() {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    result
}

fn relu(x: &Vec<Vec<f64>>) -> Vec<Vec<f64>> {
    let mut result = vec![vec![0.0; x[0].len()]; x.len()];
    for i in 0..x.len() {
        for j in 0..x[0].len() {
            result[i][j] = if x[i][j] > 0.0 { x[i][j] } else { 0.0 };
        }
    }
    result
}

fn forward_pass(input_data: &Vec<Vec<f64>>, weights: &std::collections::HashMap<&str, Vec<Vec<f64>>>) -> Vec<Vec<f64>> {
    let hidden_layer = relu(&matrix_multiply(input_data, &weights["w1"]));
    let output_layer = matrix_multiply(&hidden_layer, &weights["w2"]);
    output_layer
}

fn main() {
    let mut rng = rand::thread_rng();
    let input_data = vec![vec![rng.gen_range(0.0..1.0); 10]];
    let weights = std::collections::HashMap::from([
        ("w1", vec![vec![rng.gen_range(0.0..1.0); 5]; 10]),
        ("w2", vec![vec![rng.gen_range(0.0..1.0); 1]; 5]),
    ]);
    let result = forward_pass(&input_data, &weights);
    for row in result {
        println!("{:?}", row);
    }
}