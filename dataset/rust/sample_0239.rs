extern crate ndarray;
use ndarray::{Array1, arr1};

struct DigitalFilter {
    a: Array1<f64>,
    b: Array1<f64>,
    x: Array1<f64>,
    y: Array1<f64>,
}

impl DigitalFilter {
    fn new(coefficients: &std::collections::HashMap<&str, Vec<f64>>) -> Self {
        let a = Array1::from(coefficients["a"].clone());
        let b = Array1::from(coefficients["b"].clone());
        let x = Array1::zeros(a.len() - 1);
        let y = Array1::zeros(b.len() - 1);
        DigitalFilter { a, b, x, y }
    }

    fn process(&mut self, sample: f64) -> f64 {
        self.x = self.x.slice(s![1..]).to_owned();
        self.x.push(sample);
        let output = self.b.dot(&self.x) - &self.a.slice(s![1..]).dot(&self.y);
        self.y = self.y.slice(s![1..]).to_owned();
        self.y.push(output);
        output
    }
}

struct SignalGenerator {
    frequency: f64,
    sample_rate: usize,
    duration: f64,
}

impl SignalGenerator {
    fn new(frequency: f64, sample_rate: usize, duration: f64) -> Self {
        SignalGenerator {
            frequency,
            sample_rate,
            duration,
        }
    }

    fn generate(&self) -> Array1<f64> {
        let t: Array1<f64> = Array1::linspace(0.0, self.duration, (self.sample_rate as f64 * self.duration) as usize);
        (2.0 * std::f64::consts::PI * self.frequency * &t).mapv(f64::sin)
    }
}

fn filter_signal(signal: &Array1<f64>, coefficients: &std::collections::HashMap<&str, Vec<f64>>, sample_rate: usize, duration: f64) -> Array1<f64> {
    let mut filter = DigitalFilter::new(coefficients);
    let mut filtered_signal = Vec::new();
    for &sample in signal {
        filtered_signal.push(filter.process(sample));
    }
    Array1::from(filtered_signal)
}

fn main() {
    let coefficients: std::collections::HashMap<&str, Vec<f64>> = [
        ("a", vec![1.0, -0.9]),
        ("b", vec![0.5, 0.5]),
    ].iter().cloned().collect();
    let generator = SignalGenerator::new(5.0, 1000, 1.0);
    let signal = generator.generate();
    let filtered_signal = filter_signal(&signal, &coefficients, 1000, 1.0);
    println!("{:?}", filtered_signal);
}