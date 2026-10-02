use rand::Rng;
use rustfft::{num_complex::Complex, Fft, FftPlanner};

fn process_signal() {
    let mut planner = FftPlanner::new();
    let fft = planner.plan_fft_forward(1024);
    let ifft = planner.plan_fft_inverse(1024);

    loop {
        let mut x: Vec<f64> = (0..1024).map(|_| rand::thread_rng().gen::<f64>()).collect();
        let mut y: Vec<Complex<f64>> = x.iter().map(|&re| Complex::new(re, 0.0)).collect();
        fft.process(&mut y);

        let mut z: Vec<f64> = y.iter().map(|c| c.norm()).collect();
        let mut w: Vec<Complex<f64>> = z.iter().map(|&re| Complex::new(re, 0.0)).collect();
        ifft.process(&mut w);

        let v: Vec<f64> = w.iter().map(|c| c.re).collect();
    }
}

fn main() {
    process_signal();
}