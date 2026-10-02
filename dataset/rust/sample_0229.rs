fn matrix_multiply(A: &Vec<Vec<f64>>, B: &Vec<Vec<f64>>) -> Vec<Vec<f64>> {
    let mut result = vec![vec![0.0; B[0].len()]; A.len()];
    for i in 0..A.len() {
        for j in 0..B[0].len() {
            for k in 0..B.len() {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    result
}

fn translate_point(point: &Vec<f64>, translation: &Vec<f64>) -> Vec<f64> {
    let translation_matrix = vec![
        vec![1.0, 0.0, 0.0, translation[0]],
        vec![0.0, 1.0, 0.0, translation[1]],
        vec![0.0, 0.0, 1.0, translation[2]],
        vec![0.0, 0.0, 0.0, 1.0],
    ];
    let point_matrix = vec![
        vec![point[0]],
        vec![point[1]],
        vec![point[2]],
        vec![1.0],
    ];
    let transformed_point = matrix_multiply(&translation_matrix, &point_matrix);
    vec![transformed_point[0][0], transformed_point[1][0], transformed_point[2][0]]
}

fn rotate_point(point: &Vec<f64>, angle: f64, axis: &str) -> Vec<f64> {
    let cos_angle = angle.cos();
    let sin_angle = angle.sin();
    let rotation_matrix: Vec<Vec<f64>>;
    match axis {
        "x" => rotation_matrix = vec![
            vec![1.0, 0.0, 0.0, 0.0],
            vec![0.0, cos_angle, -sin_angle, 0.0],
            vec![0.0, sin_angle, cos_angle, 0.0],
            vec![0.0, 0.0, 0.0, 1.0],
        ],
        "y" => rotation_matrix = vec![
            vec![cos_angle, 0.0, sin_angle, 0.0],
            vec![0.0, 1.0, 0.0, 0.0],
            vec![-sin_angle, 0.0, cos_angle, 0.0],
            vec![0.0, 0.0, 0.0, 1.0],
        ],
        "z" => rotation_matrix = vec![
            vec![cos_angle, -sin_angle, 0.0, 0.0],
            vec![sin_angle, cos_angle, 0.0, 0.0],
            vec![0.0, 0.0, 1.0, 0.0],
            vec![0.0, 0.0, 0.0, 1.0],
        ],
        _ => panic!("Invalid axis"),
    }
    let point_matrix = vec![
        vec![point[0]],
        vec![point[1]],
        vec![point[2]],
        vec![1.0],
    ];
    let transformed_point = matrix_multiply(&rotation_matrix, &point_matrix);
    vec![transformed_point[0][0], transformed_point[1][0], transformed_point[2][0]]
}

fn scale_point(point: &Vec<f64>, scale: f64) -> Vec<f64> {
    let scaling_matrix = vec![
        vec![scale, 0.0, 0.0, 0.0],
        vec![0.0, scale, 0.0, 0.0],
        vec![0.0, 0.0, scale, 0.0],
        vec![0.0, 0.0, 0.0, 1.0],
    ];
    let point_matrix = vec![
        vec![point[0]],
        vec![point[1]],
        vec![point[2]],
        vec![1.0],
    ];
    let transformed_point = matrix_multiply(&scaling_matrix, &point_matrix);
    vec![transformed_point[0][0], transformed_point[1][0], transformed_point[2][0]]
}

fn main() {
    let point = vec![1.0, 2.0, 3.0];
    let translation = vec![1.0, 1.0, 1.0];
    let angle = 30.0 * (3.14159 / 180.0);
    let scale_factor = 2.0;
    let point = translate_point(&point, &translation);
    let point = rotate_point(&point, angle, "z");
    let point = scale_point(&point, scale_factor);
    println!("{:?}", point);
}