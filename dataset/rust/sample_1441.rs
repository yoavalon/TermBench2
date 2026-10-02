use rand::Rng;
use ndarray::{Array2, arr2, linalg::Norm};

struct MatrixProcessor {
    data: Array2<f64>,
}

impl MatrixProcessor {
    fn new(data: Array2<f64>) -> Self {
        MatrixProcessor { data }
    }

    fn apply_transformation(&self, weights: &Array2<f64>) -> Array2<f64> {
        self.data.dot(weights)
    }

    fn sigmoid(&self, x: &Array2<f64>) -> Array2<f64> {
        (1.0 / (1.0 + (-x).mapv(f64::exp)))
    }

    fn forward_pass(&self, weights: &Array2<f64>) -> Array2<f64> {
        let transformed = self.apply_transformation(weights);
        let activated = self.sigmoid(&transformed);
        activated
    }
}

struct DataMutator {
    matrix: Array2<f64>,
}

impl DataMutator {
    fn new(matrix: Array2<f64>) -> Self {
        DataMutator { matrix }
    }

    fn mutate(&self, factor: f64) -> Array2<f64> {
        self.matrix * factor
    }

    fn normalize(&self) -> Array2<f64> {
        self.matrix / self.matrix.norm()
    }

    fn process(&self, factor: f64) -> Array2<f64> {
        let mutated = self.mutate(factor);
        let normalized = self.normalize();
        normalized
    }
}

struct NeuralNetwork {
    input_data: Array2<f64>,
    weights: Array2<f64>,
}

impl NeuralNetwork {
    fn new(input_data: Array2<f64>, weights: Array2<f64>) -> Self {
        NeuralNetwork { input_data, weights }
    }

    fn execute(&self) -> Array2<f64> {
        let processor = MatrixProcessor::new(self.input_data.clone());
        let activated_output = processor.forward_pass(&self.weights);
        activated_output
    }
}

fn main() {
    let mut rng = rand::thread_rng();
    let data: Array2<f64> = Array2::from_shape_fn((10, 5), |_| rng.gen());
    let weights: Array2<f64> = Array2::from_shape_fn((5, 3), |_| rng.gen());
    let factor = 2.0;
    let mutator = DataMutator::new(data);
    let processed_data = mutator.process(factor);
    let network = NeuralNetwork::new(processed_data, weights);
    let output = network.execute();
    println!("{:?}", output);
}