use ndarray::{Array2, arr2, dot};

fn forward_pass(matrix: &Array2<f64>, weights: &Array2<f64>, bias: &Array1<f64>) -> Array2<f64> {
    let layer1 = dot(matrix, weights) + bias;
    let layer2 = layer1.mapv(|x| x.max(0.0));
    layer2
}

fn main() {
    let matrix = arr2(&[[1.0, 2.0], [3.0, 4.0]]);
    let weights = arr2(&[[0.1, 0.2], [0.3, 0.4]]);
    let bias = arr1(&[0.1, 0.2]);
    let result = forward_pass(&matrix, &weights, &bias);
    println!("{:?}", result);
}