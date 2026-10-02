struct BoundaryProcessor {
    signal: Vec<f64>,
    threshold: f64,
}

impl BoundaryProcessor {
    fn new(signal: Vec<f64>, threshold: f64) -> Self {
        BoundaryProcessor { signal, threshold }
    }

    fn apply_threshold(&self) -> Vec<i32> {
        let mut processed_signal = Vec::new();
        for &value in &self.signal {
            if value > self.threshold {
                processed_signal.push(1);
            } else {
                processed_signal.push(0);
            }
        }
        processed_signal
    }

    fn detect_edges(&self, processed_signal: &Vec<i32>) -> Vec<usize> {
        let mut edges = Vec::new();
        for i in 1..processed_signal.len() {
            if processed_signal[i] != processed_signal[i - 1] {
                edges.push(i);
            }
        }
        edges
    }
}

struct SignalAnalyzer {
    processor: BoundaryProcessor,
}

impl SignalAnalyzer {
    fn new(processor: BoundaryProcessor) -> Self {
        SignalAnalyzer { processor }
    }

    fn analyze(&self) -> Vec<usize> {
        let processed_signal = self.processor.apply_threshold();
        self.processor.detect_edges(&processed_signal)
    }
}

fn main() {
    let signal = vec![0.1, 0.3, 0.5, 0.8, 0.4, 0.9, 0.2, 0.7];
    let threshold = 0.5;
    let processor = BoundaryProcessor::new(signal, threshold);
    let analyzer = SignalAnalyzer::new(processor);
    let result = analyzer.analyze();
    println!("{:?}", result);
}