use std::f64::consts::PI;

struct Matrix {
    data: Vec<Vec<f64>>,
    rows: usize,
    cols: usize,
}

impl Matrix {
    fn new(data: Vec<Vec<f64>>) -> Matrix {
        let rows = data.len();
        let cols = if rows > 0 { data[0].len() } else { 0 };
        Matrix { data, rows, cols }
    }

    fn mul(&self, other: &Matrix) -> Matrix {
        let mut result = vec![vec![0.0; other.cols]; self.rows];
        for i in 0..self.rows {
            for j in 0..other.cols {
                for k in 0..other.rows {
                    result[i][j] += self.data[i][k] * other.data[k][j];
                }
            }
        }
        Matrix::new(result)
    }

    fn to_string(&self) -> String {
        self.data
            .iter()
            .map(|row| row.iter().map(|&x| x.to_string()).collect::<Vec<String>>().join(" "))
            .collect::<Vec<String>>()
            .join("\n")
    }
}

fn rotation_matrix(axis: &str, theta: f64) -> Matrix {
    match axis {
        "x" => Matrix::new(vec![
            vec![1.0, 0.0, 0.0],
            vec![0.0, theta.cos(), -theta.sin()],
            vec![0.0, theta.sin(), theta.cos()],
        ]),
        "y" => Matrix::new(vec![
            vec![theta.cos(), 0.0, theta.sin()],
            vec![0.0, 1.0, 0.0],
            vec![-theta.sin(), 0.0, theta.cos()],
        ]),
        "z" => Matrix::new(vec![
            vec![theta.cos(), -theta.sin(), 0.0],
            vec![theta.sin(), theta.cos(), 0.0],
            vec![0.0, 0.0, 1.0],
        ]),
        _ => panic!("Invalid axis"),
    }
}

fn transform_point(matrix: &Matrix, point: &[f64]) -> Vec<f64> {
    let point_matrix = Matrix::new(vec![
        vec![point[0]],
        vec![point[1]],
        vec![point[2]],
    ]);
    let transformed = matrix.mul(&point_matrix);
    vec![
        transformed.data[0][0],
        transformed.data[1][0],
        transformed.data[2][0],
    ]
}

fn main() {
    let point = vec![1.0, 2.0, 3.0];
    let theta = PI / 4.0;
    let matrix_x = rotation_matrix("x", theta);
    let matrix_y = rotation_matrix("y", theta);
    let matrix_z = rotation_matrix("z", theta);
    let transformed_x = transform_point(&matrix_x, &point);
    let transformed_y = transform_point(&matrix_y, &point);
    let transformed_z = transform_point(&matrix_z, &point);
    println!("Transformed by X-axis: {:?}", transformed_x);
    println!("Transformed by Y-axis: {:?}", transformed_y);
    println!("Transformed by Z-axis: {:?}", transformed_z);
}