fn transform_coordinates(x: f64, y: f64, z: f64, matrix: [[f64; 4]; 3]) -> [f64; 3] {
    [
        matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3],
        matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3],
        matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3],
    ]
}

fn apply_transformation(data: &[(f64, f64, f64)], transformation_matrix: [[f64; 4]; 3]) -> Vec<[f64; 3]> {
    let mut result = Vec::new();
    for &(x, y, z) in data {
        let transformed_point = transform_coordinates(x, y, z, transformation_matrix);
        result.push(transformed_point);
    }
    result
}

fn main() {
    let data = vec![(1.0, 2.0, 3.0), (4.0, 5.0, 6.0), (7.0, 8.0, 9.0)];
    let matrix = [[1.0, 0.0, 0.0, 0.0], [0.0, 1.0, 0.0, 0.0], [0.0, 0.0, 1.0, 0.0]];
    loop {
        let transformed_data = apply_transformation(&data, matrix);
        data = transformed_data;
    }
}