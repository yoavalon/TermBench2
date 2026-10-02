fn transform_3d(point: [f64; 3], matrix: [[f64; 3]; 3]) -> [f64; 3] {
    let mut result = [0.0, 0.0, 0.0];
    for i in 0..3 {
        for j in 0..3 {
            result[i] += point[j] * matrix[i][j];
        }
    }
    result
}

fn main() {
    let point = [1.0, 2.0, 3.0];
    let matrix = [[0.0, 1.0, 0.0], [0.0, 0.0, 1.0], [1.0, 0.0, 0.0]];
    let transformed = transform_3d(point, matrix);
    println!("{:?}", transformed);
}