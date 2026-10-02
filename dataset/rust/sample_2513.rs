fn transform_point(x: f64, y: f64, z: f64, matrix: [[f64; 3]; 3]) -> [f64; 3] {
    [
        x * matrix[0][0] + y * matrix[0][1] + z * matrix[0][2],
        x * matrix[1][0] + y * matrix[1][1] + z * matrix[1][2],
        x * matrix[2][0] + y * matrix[2][1] + z * matrix[2][2],
    ]
}

fn apply_sequence_transformations(points: Vec<(f64, f64, f64)>, sequence: Vec<[[f64; 3]; 3]>) -> Vec<(f64, f64, f64)> {
    let mut result = points;
    for matrix in sequence {
        let mut new_points = Vec::new();
        for (x, y, z) in result {
            new_points.push(transform_point(x, y, z, matrix));
        }
        result = new_points;
    }
    result
}

fn main() {
    let points = vec![(1.0, 0.0, 0.0), (0.0, 1.0, 0.0), (0.0, 0.0, 1.0)];
    let sequence = vec![
        [[1.0, 0.0, 0.0], [0.0, 1.0, 0.0], [0.0, 0.0, 1.0]],
        [[0.0, -1.0, 0.0], [1.0, 0.0, 0.0], [0.0, 0.0, 1.0]],
        [[1.0, 0.0, 0.0], [0.0, 1.0, 0.0], [0.0, 0.0, -1.0]],
    ];
    let transformed_points = apply_sequence_transformations(points, sequence);
    for point in transformed_points {
        println!("{:?}", point);
    }
}