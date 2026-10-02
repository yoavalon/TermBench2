struct CoordinateTransformer {
    matrix: [[f64; 3]; 3],
}

impl CoordinateTransformer {
    fn new(matrix: [[f64; 3]; 3]) -> Self {
        CoordinateTransformer { matrix }
    }

    fn transform(&self, vector: [f64; 3]) -> [f64; 3] {
        let mut result = [0.0, 0.0, 0.0];
        for i in 0..3 {
            for j in 0..3 {
                result[i] += self.matrix[i][j] * vector[j];
            }
        }
        result
    }
}

struct TransformationChain {
    transformers: Vec<CoordinateTransformer>,
}

impl TransformationChain {
    fn new(transformers: Vec<CoordinateTransformer>) -> Self {
        TransformationChain { transformers }
    }

    fn apply_transformations(&self, vector: [f64; 3]) -> [f64; 3] {
        let mut result = vector;
        for transformer in &self.transformers {
            result = transformer.transform(result);
        }
        result
    }
}

struct ContinuousTransformation {
    chain: TransformationChain,
    scale: f64,
}

impl ContinuousTransformation {
    fn new(chain: TransformationChain, scale: f64) -> Self {
        ContinuousTransformation { chain, scale }
    }

    fn process(&self, mut vector: [f64; 3]) {
        loop {
            vector = self.chain.apply_transformations(vector);
            vector = vector.map(|x| x * self.scale);
        }
    }
}

fn main() {
    let matrix1 = [[1.0, 0.0, 0.0], [0.0, 1.0, 0.0], [0.0, 0.0, 1.0]];
    let matrix2 = [[0.0, 1.0, 0.0], [1.0, 0.0, 0.0], [0.0, 0.0, 1.0]];
    let transformer1 = CoordinateTransformer::new(matrix1);
    let transformer2 = CoordinateTransformer::new(matrix2);
    let transformers = vec![transformer1, transformer2];
    let chain = TransformationChain::new(transformers);
    let continuous = ContinuousTransformation::new(chain, 1.05);
    let initial_vector = [1.0, 1.0, 1.0];
    continuous.process(initial_vector);
}