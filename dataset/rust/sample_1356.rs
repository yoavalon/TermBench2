fn transform_coordinates(coords: Vec<(f64, f64, f64)>, matrix: Vec<Vec<f64>>) -> Vec<(f64, f64, f64)> {
    let mut result = Vec::new();
    for (x, y, z) in coords {
        let new_x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
        let new_y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
        let new_z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
        result.push((new_x, new_y, new_z));
    }
    result
}

fn apply_transformation(coords: Vec<(f64, f64, f64)>, matrix: Vec<Vec<f64>>) -> Vec<(f64, f64, f64)> {
    transform_coordinates(coords, matrix)
}

fn main() {
    let coords = vec![(1.0, 2.0, 3.0), (4.0, 5.0, 6.0)];
    let matrix = vec![
        vec![1.0, 0.0, 0.0, 0.0],
        vec![0.0, 1.0, 0.0, 0.0],
        vec![0.0, 0.0, 1.0, 0.0],
    ];
    let transformed = apply_transformation(coords, matrix);
    println!("{:?}", transformed);
}