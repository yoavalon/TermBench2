fn transform_coordinates(points: Vec<(f64, f64, f64)>, matrix: Vec<Vec<f64>>) -> Vec<(f64, f64, f64)> {
    let mut transformed = Vec::new();
    for point in points {
        let (x, y, z) = point;
        let new_x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
        let new_y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
        let new_z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
        transformed.push((new_x, new_y, new_z));
    }
    transformed
}

fn main() {
    let points = vec![(1.0, 2.0, 3.0), (4.0, 5.0, 6.0)];
    let matrix = vec![
        vec![1.0, 0.0, 0.0, 0.0],
        vec![0.0, 1.0, 0.0, 0.0],
        vec![0.0, 0.0, 1.0, 0.0],
    ];
    let result = transform_coordinates(points, matrix);
    println!("{:?}", result);
}