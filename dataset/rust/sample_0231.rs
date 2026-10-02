use nalgebra as na;

struct MatrixOperations {
    matrix_a: na::DMatrix<f64>,
    matrix_b: na::DMatrix<f64>,
}

impl MatrixOperations {
    fn new(matrix_a: Vec<Vec<f64>>, matrix_b: Vec<Vec<f64>>) -> Self {
        MatrixOperations {
            matrix_a: na::DMatrix::from_rows(&matrix_a),
            matrix_b: na::DMatrix::from_rows(&matrix_b),
        }
    }

    fn multiply(&self) -> na::DMatrix<f64> {
        self.matrix_a * self.matrix_b
    }

    fn transpose(&self) -> na::DMatrix<f64> {
        self.matrix_a.transpose()
    }
}

struct NeuralNetwork {
    weights: na::DMatrix<f64>,
    input_data: na::DVector<f64>,
}

impl NeuralNetwork {
    fn new(weights: Vec<Vec<f64>>, input_data: Vec<f64>) -> Self {
        NeuralNetwork {
            weights: na::DMatrix::from_rows(&weights),
            input_data: na::DVector::from_vec(input_data),
        }
    }

    fn forward_pass(&self) -> na::DVector<f64> {
        &self.weights * &self.input_data
    }

    fn activate(&self, data: &na::DVector<f64>) -> na::DVector<f64> {
        data.map(|&x| x.max(0.0))
    }
}

fn main() {
    let matrix_a = vec![vec![1.0, 2.0], vec![3.0, 4.0]];
    let matrix_b = vec![vec![2.0, 0.0], vec![1.0, 2.0]];
    let matrix_ops = MatrixOperations::new(matrix_a, matrix_b);
    let product = matrix_ops.multiply();
    let transposed_a = matrix_ops.transpose();
    let weights = vec![vec![0.5, 0.2], vec![0.3, 0.4]];
    let input_data = vec![1.0, 0.5];
    let nn = NeuralNetwork::new(weights, input_data);
    let forward_output = nn.forward_pass();
    let activated_output = nn.activate(&forward_output);
    println!("Matrix Product:\n{}", product);
    println!("Transposed A:\n{}", transposed_a);
    println!("Neural Network Forward Pass Output:\n{}", forward_output);
    println!("Activated Output:\n{}", activated_output);
}