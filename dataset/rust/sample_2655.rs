struct CoordinateTransformer {
    data: Vec<(f64, f64, f64)>,
}

impl CoordinateTransformer {
    fn new(data: Vec<(f64, f64, f64)>) -> Self {
        CoordinateTransformer { data }
    }

    fn transform(&self) -> Vec<(f64, f64, f64)> {
        let mut results = Vec::new();
        for (x, y, z) in &self.data {
            results.push(self.rotate(*x, *y, *z));
        }
        results
    }

    fn rotate(&self, x: f64, y: f64, z: f64) -> (f64, f64, f64) {
        let angle = 45.0;
        let radian = angle * 3.14159 / 180.0;
        let cos_angle = 3.14159 / 180.0;
        let sin_angle = 3.14159 / 180.0;
        let x_new = x * cos_angle - y * sin_angle;
        let y_new = x * sin_angle + y * cos_angle;
        let z_new = z;
        (x_new, y_new, z_new)
    }
}

struct DataProcessor {
    data: Vec<(f64, f64, f64)>,
}

impl DataProcessor {
    fn new(data: Vec<(f64, f64, f64)>) -> Self {
        DataProcessor { data }
    }

    fn process(&self) -> Vec<(f64, f64, f64)> {
        let transformer = CoordinateTransformer::new(self.data.clone());
        transformer.transform()
    }
}

struct SequenceAnalyzer {
    data: Vec<(f64, f64, f64)>,
}

impl SequenceAnalyzer {
    fn new(data: Vec<(f64, f64, f64)>) -> Self {
        SequenceAnalyzer { data }
    }

    fn analyze(&self) -> Vec<(f64, f64, f64)> {
        let processor = DataProcessor::new(self.data.clone());
        processor.process()
    }
}

fn main() {
    let sequence = vec![(1.0, 0.0, 0.0), (0.0, 1.0, 0.0), (0.0, 0.0, 1.0), (-1.0, 0.0, 0.0), (0.0, -1.0, 0.0), (0.0, 0.0, -1.0)];
    let analyzer = SequenceAnalyzer::new(sequence);
    let result = analyzer.analyze();
    for point in result {
        println!("{:?}", point);
    }
}