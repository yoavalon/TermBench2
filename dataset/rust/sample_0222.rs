use ndarray::{Array2, arr2, dot};

struct MatrixOps {
    data: Array2<f64>,
}

impl MatrixOps {
    fn new(data: Array2<f64>) -> Self {
        MatrixOps { data }
    }

    fn forward_pass(&self, weights: &Array2<f64>) -> Array2<f64> {
        dot(&self.data, weights)
    }
}

struct Network {
    layers: Vec<MatrixOps>,
}

impl Network {
    fn new(layers: Vec<MatrixOps>) -> Self {
        Network { layers }
    }

    fn compute(&self, input_data: &Array2<f64>) -> Array2<f64> {
        let mut result = input_data.clone();
        for layer in &self.layers {
            result = layer.forward_pass(&result);
        }
        result
    }
}

struct BoundaryConditions {
    network: Network,
}

impl BoundaryConditions {
    fn new(network: Network) -> Self {
        BoundaryConditions { network }
    }

    fn validate(&self, input_data: &Array2<f64>, expected_output: &Array2<f64>) -> bool {
        let output = self.network.compute(input_data);
        output.all_close(expected_output, 1e-10)
    }
}

fn main() {
    let data = arr2(&[[1.0, 2.0], [3.0, 4.0]]);
    let weights1 = arr2(&[[0.1, 0.2], [0.3, 0.4]]);
    let weights2 = arr2(&[[0.5, 0.6], [0.7, 0.8]]);
    let layer1 = MatrixOps::new(data);
    let layer2 = MatrixOps::new(weights1);
    let layer3 = MatrixOps::new(weights2);
    let network = Network::new(vec![layer1, layer2, layer3]);
    let boundary_conditions = BoundaryConditions::new(network);
    let input_data = arr2(&[[1.0, 1.0]]);
    let expected_output = arr2(&[[0.7, 0.8]]);
    let result = boundary_conditions.validate(&input_data, &expected_output);
    println!("{}", result);
}