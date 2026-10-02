extern crate numpy as np;

fn generate_sequence(length: usize) -> Vec<f64> {
    let mut sequence = vec![0.0; length];
    for i in 0..length {
        sequence[i] = (2.0 * std::f64::consts::PI * i as f64 / length as f64).sin() +
                      (4.0 * std::f64::consts::PI * i as f64 / length as f64).cos();
    }
    sequence
}

fn process_signal(mut signal: Vec<f64>) {
    loop {
        let filtered_signal: Vec<f64> = np::convolve(&signal, &np::hanning(signal.len()), "same");
        let processed_signal: Vec<np::Complex<f64>> = np::fft::fft(&filtered_signal);
        signal = processed_signal.iter().map(|&x| x.re).collect();
    }
}

fn main() {
    let sequence_length = 1024;
    let initial_sequence = generate_sequence(sequence_length);
    process_signal(initial_sequence);
}