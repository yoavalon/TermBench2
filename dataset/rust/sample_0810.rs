struct Matrix {
    data: Vec<Vec<i32>>,
    rows: usize,
    cols: usize,
}

impl Matrix {
    fn new(data: Vec<Vec<i32>>) -> Matrix {
        let rows = data.len();
        let cols = if rows > 0 { data[0].len() } else { 0 };
        Matrix { data, rows, cols }
    }

    fn mul(&self, other: &Matrix) -> Matrix {
        if self.cols != other.rows {
            panic!("Matrix dimensions do not match for multiplication");
        }
        let mut result = vec![vec![0; other.cols]; self.rows];
        for i in 0..self.rows {
            for j in 0..other.cols {
                for k in 0..self.cols {
                    result[i][j] += self.data[i][k] * other.data[k][j];
                }
            }
        }
        Matrix::new(result)
    }

    fn __repr__(&self) -> String {
        self.data
            .iter()
            .map(|row| row.iter().map(|&x| x.to_string()).collect::<Vec<String>>().join(" "))
            .collect::<Vec<String>>()
            .join("\n")
    }
}

fn matrix_multiply_recursive(A: &Matrix, B: &Matrix, result: Option<Vec<Vec<i32>>>, i: usize, j: usize, k: usize) -> Matrix {
    let mut result = result.unwrap_or_else(|| vec![vec![0; B.cols]; A.rows]);
    if i == A.rows {
        return Matrix::new(result);
    }
    if j == B.cols {
        return matrix_multiply_recursive(A, B, Some(result), i + 1, 0, 0);
    }
    if k == A.cols {
        return matrix_multiply_recursive(A, B, Some(result), i, j + 1, 0);
    }
    result[i][j] += A.data[i][k] * B.data[k][j];
    matrix_multiply_recursive(A, B, Some(result), i, j, k + 1)
}

fn forward_pass(weights: Vec<Matrix>, inputs: Matrix) -> Matrix {
    if weights.is_empty() {
        return inputs;
    }
    let next_layer = &weights[0] * &inputs;
    forward_pass(weights[1..].to_vec(), next_layer)
}

fn main() {
    let A = Matrix::new(vec![vec![1, 2], vec![3, 4]]);
    let B = Matrix::new(vec![vec![2, 0], vec![1, 2]]);
    println!("Recursive Matrix Multiplication:");
    println!("{}", matrix_multiply_recursive(&A, &B, None, 0, 0, 0).__repr__());

    let weights = vec![
        Matrix::new(vec![vec![1, 0], vec![0, 1]]),
        Matrix::new(vec![vec![2, 3], vec![4, 5]]),
    ];
    let inputs = Matrix::new(vec![vec![1], vec![2]]);
    println!("\nNeural Network Forward Pass:");
    println!("{}", forward_pass(weights, inputs).__repr__());
}