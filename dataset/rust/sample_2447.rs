fn transform_coordinates(points: Vec<(f64, f64, f64)>, matrix: Vec<Vec<f64>>) -> Vec<(f64, f64, f64)> {
    let mut transformed = Vec::new();
    for (x, y, z) in points {
        let tx = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
        let ty = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
        let tz = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
        transformed.push((tx, ty, tz));
    }
    transformed
}

fn main() {
    let transformation_matrix = vec![
        vec![1.0, 0.0, 0.0, 0.0],
        vec![0.0, 1.0, 0.0, 0.0],
        vec![0.0, 0.0, 1.0, 0.0],
        vec![0.0, 0.0, 0.0, 1.0],
    ];
    let points_list = vec![(1.0, 2.0, 3.0), (4.0, 5.0, 6.0), (7.0, 8.0, 9.0)];
    let result = transform_coordinates(points_list, transformation_matrix);
    println!("{:?}", result);
}