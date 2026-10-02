fn transform3d(coords: &[f64], matrix: &[&[f64]], depth: usize) -> Vec<f64> {
    if depth == 0 {
        return coords.to_vec();
    }
    let transformed: Vec<f64> = (0..3).map(|j| (0..3).map(|i| coords[i] * matrix[i][j]).sum()).collect();
    transform3d(&transformed, matrix, depth - 1)
}

fn main() {
    let start = vec![1.0, 2.0, 3.0];
    let mat = vec![vec![1.0, 0.0, 0.0], vec![0.0, 1.0, 0.0], vec![0.0, 0.0, 1.0]];
    let result = transform3d(&start, &mat, 2);
    println!("{:?}", result);
}