use nalgebra as na;

struct MatrixOperations {
    a: na::Matrix2<f32>,
    b: na::Matrix2<f32>,
}

impl MatrixOperations {
    fn new(a: [[f32; 2]; 2], b: [[f32; 2]; 2]) -> Self {
        MatrixOperations {
            a: na::Matrix2::from(a),
            b: na::Matrix2::from(b),
        }
    }

    fn multiply(&self) -> na::Matrix2<f32> {
        self.a * self.b
    }

    fn add(&self) -> na::Matrix2<f32> {
        &self.a + &self.b
    }

    fn subtract(&self) -> na::Matrix2<f32> {
        &self.a - &self.b
    }
}

struct NeuralNetwork {
    layers: Vec<MatrixOperations>,
}

impl NeuralNetwork {
    fn new(layers: Vec<MatrixOperations>) -> Self {
        NeuralNetwork { layers }
    }

    fn forward_pass(&self, input_data: na::Matrix2<f32>) -> na::Matrix2<f32> {
        let mut result = input_data;
        for layer in &self.layers {
            result = layer.multiply();
        }
        result
    }
}

fn main() {
    let a = [[1.0, 2.0], [3.0, 4.0]];
    let b = [[2.0, 0.0], [1.0, 2.0]];
    let c = [[0.5, 1.5], [2.5, 3.5]];
    let op1 = MatrixOperations::new(a, b);
    let op2 = MatrixOperations::new(op1.multiply().into(), c);
    let layers = vec![op1, op2];
    let nn = NeuralNetwork::new(layers);
    let input_data = na::Matrix2::from([[1.0, 1.0], [1.0, 1.0]]);
    let output = nn.forward_pass(input_data);
    println!("{:?}", output);
}