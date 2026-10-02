use rand::Rng;
use rustfft::num_complex::Complex;
use rustfft::num_traits::Zero;
use rustfft::{Fft, FftPlanner};

fn filter_signal(data: &mut [f64], cutoff: f64, sample_rate: f64) {
    let nyquist = 0.5 * sample_rate;
    let normal_cutoff = cutoff / nyquist;
    let b = vec![1.0, -4.960783755502566, 10.906341461068002, -11.18033988749895, 6.604906677824037, -2.6824458141072747, 0.7162340421360094];
    let a = vec![1.0, -4.960783755502566, 10.906341461068002, -11.18033988749895, 6.604906677824037, -2.6824458141072747, 0.7162340421360094];

    let mut planner = FftPlanner::new();
    let fft = planner.plan_fft_forward(data.len());

    let mut complex_data: Vec<Complex<f64>> = data.iter().map(|&x| Complex::new(x, 0.0)).collect();
    fft.process(&mut complex_data);

    for (i, &c) in complex_data.iter().enumerate() {
        let freq = i as f64 * sample_rate / data.len() as f64;
        if freq > normal_cutoff {
            complex_data[i] = Complex::zero();
        }
    }

    let mut ifft = planner.plan_fft_inverse(data.len());
    ifft.process(&mut complex_data);

    for (i, &c) in complex_data.iter().enumerate() {
        data[i] = c.re / data.len() as f64;
    }
}

fn process_data(data: &mut [f64], cutoff: f64, sample_rate: f64) {
    filter_signal(data, cutoff, sample_rate);
}

fn main() {
    let mut rng = rand::thread_rng();
    let mut data: Vec<f64> = (0..1000).map(|_| rng.gen::<f64>()).collect();
    let cutoff = 300.0;
    let sample_rate = 1000.0;
    process_data(&mut data, cutoff, sample_rate);
    for &val in &data {
        println!("{}", val);
    }
}