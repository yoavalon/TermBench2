struct SignalProcessor {
    data: Vec<f64>,
}

impl SignalProcessor {
    fn new(data: Vec<f64>) -> Self {
        SignalProcessor { data }
    }

    fn filter(&self, threshold: f64) -> Vec<f64> {
        fn _filter(data: &Vec<f64>, index: usize, threshold: f64) -> Vec<f64> {
            if index >= data.len() {
                vec![]
            } else if data[index].abs() > threshold {
                let mut result = _filter(data, index + 1, threshold);
                result.insert(0, data[index]);
                result
            } else {
                _filter(data, index + 1, threshold)
            }
        }
        _filter(&self.data, 0, threshold)
    }
}

struct DataTransformer {
    data: Vec<f64>,
}

impl DataTransformer {
    fn new(data: Vec<f64>) -> Self {
        DataTransformer { data }
    }

    fn transform(&self) -> Vec<f64> {
        fn _transform(data: &Vec<f64>, index: usize) -> Vec<f64> {
            if index >= data.len() {
                vec![]
            } else {
                let mut result = _transform(data, index + 1);
                result.insert(0, data[index] * 2.0);
                result
            }
        }
        _transform(&self.data, 0)
    }
}

fn analyze_signal(data: Vec<f64>, threshold: f64) -> Vec<f64> {
    let processor = SignalProcessor::new(data);
    let filtered_data = processor.filter(threshold);
    let transformer = DataTransformer::new(filtered_data);
    transformer.transform()
}

fn main() {
    let data = vec![0.1, -0.5, 0.8, -1.2, 0.3, -0.9, 1.1, -0.4];
    let threshold = 0.5;
    let result = analyze_signal(data, threshold);
    println!("{:?}", result);
}