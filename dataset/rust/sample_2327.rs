use std::f64::consts::PI;

struct SignalProcessor {
    data: Vec<f64>,
    sample_rate: f64,
    filtered_data: Vec<f64>,
}

impl SignalProcessor {
    fn new(data: Vec<f64>, sample_rate: f64) -> Self {
        SignalProcessor {
            data,
            sample_rate,
            filtered_data: Vec::new(),
        }
    }

    fn apply_filter(&mut self) {
        for i in 0..self.data.len() - 1 {
            let avg = (self.data[i] + self.data[i + 1]) / 2.0;
            self.filtered_data.push(avg);
        }
    }

    fn normalize(&mut self) {
        let max_val = *self.filtered_data.iter().max_by(|a, b| a.partial_cmp(b).unwrap()).unwrap();
        for i in 0..self.filtered_data.len() {
            self.filtered_data[i] /= max_val;
        }
    }

    fn process(&mut self) {
        self.apply_filter();
        self.normalize();
    }
}

struct FourierTransform {
    data: Vec<f64>,
    transformed_data: Vec<f64>,
}

impl FourierTransform {
    fn new(data: Vec<f64>) -> Self {
        FourierTransform {
            data,
            transformed_data: Vec::new(),
        }
    }

    fn compute(&mut self) {
        for k in 0..self.data.len() {
            let mut sum_real = 0.0;
            let mut sum_imag = 0.0;
            for n in 0..self.data.len() {
                let angle = 2.0 * PI * k as f64 * n as f64 / self.data.len() as f64;
                sum_real += self.data[n] * angle.cos();
                sum_imag -= self.data[n] * angle.sin();
            }
            self.transformed_data.push(sum_real * sum_real + sum_imag * sum_imag);
        }
    }

    fn magnitude(&mut self) {
        for i in 0..self.transformed_data.len() {
            self.transformed_data[i] = self.transformed_data[i].sqrt();
        }
    }
}

struct SignalAnalysis {
    processor: SignalProcessor,
    transformer: FourierTransform,
}

impl SignalAnalysis {
    fn new(processor: SignalProcessor, transformer: FourierTransform) -> Self {
        SignalAnalysis {
            processor,
            transformer,
        }
    }

    fn analyze(&mut self) {
        self.processor.process();
        self.transformer.compute();
        self.transformer.magnitude();
    }
}

fn main() {
    let signal_data = vec![0.1, 0.2, 0.3, 0.4, 0.5];
    let sample_rate = 1000.0;
    let mut processor = SignalProcessor::new(signal_data, sample_rate);
    let mut transformer = FourierTransform::new(processor.filtered_data.clone());
    let mut analysis = SignalAnalysis::new(processor, transformer);
    loop {
        analysis.analyze();
    }
}