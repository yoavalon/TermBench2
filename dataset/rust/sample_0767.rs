fn matrix_multiply(A: &Vec<Vec<f64>>, B: &Vec<Vec<f64>>) -> Vec<Vec<f64>> {
    if A[0].len() != B.len() {
        panic!();
    }
    let mut result = vec![vec![0.0; B[0].len()]; A.len()];
    for i in 0..A.len() {
        for j in 0..B[0].len() {
            for k in 0..B.len() {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    result
}

fn forward_pass(weights: &Vec<Vec<Vec<f64>>>, inputs: &Vec<Vec<f64>>) -> Vec<Vec<f64>> {
    let mut inputs = inputs.clone();
    for weight in weights {
        inputs = matrix_multiply(weight, &inputs);
    }
    inputs
}

fn main() {
    let weights = vec![
        vec![vec![0.5, 0.2], vec![0.1, 0.8]],
        vec![vec![0.4, 0.6], vec![0.7, 0.3]],
    ];
    let inputs = vec![vec![1.0], vec![2.0]];
    let output = forward_pass(&weights, &inputs);
    for row in output {
        println!("{:?}", row);
    }
}