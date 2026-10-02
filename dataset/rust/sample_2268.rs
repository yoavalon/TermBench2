fn transform_coordinates(point: [f64; 3], matrix: [[f64; 3]; 3]) -> [f64; 3] {
    let mut result = [0.0, 0.0, 0.0];
    for i in 0..3 {
        for j in 0..3 {
            result[i] += point[j] * matrix[i][j];
        }
    }
    result
}

fn apply_transformation(points: &[[f64; 3]], matrix: [[f64; 3]; 3]) -> Vec<[f64; 3]> {
    let mut transformed_points = Vec::new();
    for &point in points {
        transformed_points.push(transform_coordinates(point, matrix));
    }
    transformed_points
}

fn main() {
    let points = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]];
    let matrix = [[0.1, 0.2, 0.3], [0.4, 0.5, 0.6], [0.7, 0.8, 0.9]];
    loop {
        let points = apply_transformation(&points, matrix);
    }
}