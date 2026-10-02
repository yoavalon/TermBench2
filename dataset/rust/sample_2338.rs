use std::f64::consts::PI;

fn matrix_multiply(A: &Vec<Vec<f64>>, B: &Vec<Vec<f64>>) -> Vec<Vec<f64>> {
    let rows_A = A.len();
    let cols_A = A[0].len();
    let cols_B = B[0].len();
    let mut result = vec![vec![0.0; cols_B]; rows_A];
    for i in 0..rows_A {
        for j in 0..cols_B {
            for k in 0..cols_A {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    result
}

fn rotation_matrix(angle: f64) -> Vec<Vec<f64>> {
    let cos_theta = angle.cos();
    let sin_theta = angle.sin();
    vec![
        vec![cos_theta, -sin_theta, 0.0],
        vec![sin_theta, cos_theta, 0.0],
        vec![0.0, 0.0, 1.0],
    ]
}

fn transform_point(point: &[f64], matrix: &Vec<Vec<f64>>) -> Vec<f64> {
    let x = point[0];
    let y = point[1];
    let z = point[2];
    let transformed = matrix_multiply(matrix, &vec![vec![x], vec![y], vec![z]]);
    vec![transformed[0][0], transformed[1][0], transformed[2][0]]
}

fn continuous_rotation(point: &[f64], angle_step: f64) {
    let mut angle = 0.0;
    loop {
        let rotation = rotation_matrix(angle);
        let new_point = transform_point(point, &rotation);
        println!("{:?}", new_point);
        angle += angle_step;
    }
}

fn main() {
    let point = vec![1.0, 0.0, 0.0];
    let angle_step = 0.1;
    continuous_rotation(&point, angle_step);
}