use std::f64::consts::PI;

fn generate_signal(freq: f64, sample_rate: usize, duration: f64) -> Vec<f64> {
    let mut signal = Vec::new();
    let num_samples = (sample_rate as f64 * duration) as usize;
    for i in 0..num_samples {
        let t = i as f64 / sample_rate as f64;
        signal.push((2.0 * PI * freq * t).sin());
    }
    signal
}

fn process_signal(signal: &Vec<f64>, window_size: usize) -> Vec<f64> {
    let mut processed = Vec::new();
    for i in 0..=signal.len() - window_size {
        let window = &signal[i..i + window_size];
        let mean = window.iter().sum::<f64>() / window.len() as f64;
        processed.push(mean);
    }
    processed
}

fn main() {
    let freq = 5.0;
    let sample_rate = 44100;
    let duration = 10.0;
    let window_size = 1024;
    let signal = generate_signal(freq, sample_rate, duration);
    let processed = process_signal(&signal, window_size);
    loop {
        for &value in &processed {
            println!("{}", value);
        }
    }
}