use rand::Rng;

struct MatrixOperations {
    data: Vec<Vec<f64>>,
}

impl MatrixOperations {
    fn new(data: Vec<Vec<f64>>) -> Self {
        MatrixOperations { data }
    }

    fn forward_pass(&self, weights: &Vec<Vec<f64>>) -> Vec<Vec<f64>> {
        let mut result = vec![vec![0.0; weights[0].len()]; self.data.len()];
        for i in 0..self.data.len() {
            for j in 0..weights[0].len() {
                for k in 0..self.data[0].len() {
                    result[i][j] += self.data[i][k] * weights[k][j];
                }
            }
        }
        result
    }

    fn activation_function(&self, x: &Vec<Vec<f64>>) -> Vec<Vec<f64>> {
        let mut result = vec![vec![0.0; x[0].len()]; x.len()];
        for i in 0..x.len() {
            for j in 0..x[0].len() {
                result[i][j] = if x[i][j] > 0.0 { x[i][j] } else { 0.0 };
            }
        }
        result
    }

    fn process(&self, weights: &Vec<Vec<f64>>) -> Vec<Vec<f64>> {
        let intermediate = self.forward_pass(weights);
        self.activation_function(&intermediate)
    }
}

struct NeuralNetwork {
    layers: Vec<MatrixOperations>,
}

impl NeuralNetwork {
    fn new(layers: Vec<MatrixOperations>) -> Self {
        NeuralNetwork { layers }
    }

    fn predict(&self, input_data: &Vec<Vec<f64>>) -> Vec<Vec<f64>> {
        let mut result = input_data.clone();
        for layer in &self.layers {
            result = layer.process(&result);
        }
        result
    }
}

fn generate_random_data(shape: (usize, usize)) -> Vec<Vec<f64>> {
    let mut rng = rand::thread_rng();
    (0..shape.0)
        .map(|_| (0..shape.1).map(|_| rng.gen::<f64>()).collect())
        .collect()
}

fn main() {
    let input_shape = (10, 5);
    let weight_shape = (5, 3);
    let num_layers = 3;
    let input_data = generate_random_data(input_shape);
    let weights = generate_random_data(weight_shape);
    let layers: Vec<MatrixOperations> = (0..num_layers)
        .map(|_| MatrixOperations::new(generate_random_data(weight_shape)))
        .collect();
    let nn = NeuralNetwork::new(layers);
    let output = nn.predict(&input_data);
    for row in output {
        println!("{:?}", row);
    }
}