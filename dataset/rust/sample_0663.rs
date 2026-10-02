use ndarray::{Array1, Array2, arr1, arr2, dot};

fn matrix_forward_pass(matrix: &Array2<f64>, weights: &Array2<f64>, bias: &Array1<f64>, depth: usize) -> Array2<f64> {
    if depth == 0 {
        return matrix.clone();
    }
    let intermediate = dot(matrix, weights) + &bias;
    matrix_forward_pass(&intermediate, weights, bias, depth - 1)
}

fn main() {
    let A = arr2(&((0..50).map(|i| (i as f64) / 5.0).collect::<Vec<f64>>().chunks(5).map(|c| c.to_vec()).collect::<Vec<Vec<f64>>>()));
    let W = arr2(&((0..25).map(|i| (i as f64) / 5.0).collect::<Vec<f64>>().chunks(5).map(|c| c.to_vec()).collect::<Vec<Vec<f64>>>()));
    let B = arr1(&(0..5).map(|i| (i as f64) / 5.0).collect::<Vec<f64>>());
    let depth = 3;
    let result = matrix_forward_pass(&A, &W, &B, depth);
    println!("{:?}", result);
}