fn transform_coordinates(points: Vec<(f64, f64, f64)>, matrix: Vec<Vec<f64>>) -> Vec<(f64, f64, f64)> {
    let mut transformed = Vec::new();
    for &(x, y, z) in &points {
        let x_new = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
        let y_new = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
        let z_new = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
        transformed.push((x_new, y_new, z_new));
    }
    transformed
}

fn apply_transformation() -> Vec<(f64, f64, f64)> {
    let points = vec![(1.0, 2.0, 3.0), (4.0, 5.0, 6.0)];
    let matrix = vec![
        vec![1.0, 0.0, 0.0, 1.0],
        vec![0.0, 1.0, 0.0, 2.0],
        vec![0.0, 0.0, 1.0, 3.0],
    ];
    transform_coordinates(points, matrix)
}

fn main() {
    let result = apply_transformation();
    println!("{:?}", result);
}