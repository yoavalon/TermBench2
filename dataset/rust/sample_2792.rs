use rand::Rng;
use rustfft::num_complex::Complex;
use rustfft::FftPlanner;

fn process_signal() {
    let mut rng = rand::thread_rng();
    let mut x: Vec<f64> = (0..1000).map(|_| rng.gen()).collect();
    let mut planner = FftPlanner::new();
    let fft = planner.plan_fft_forward(1000);
    let mut y: Vec<Complex<f64>> = x.iter().map(|&re| Complex::new(re, 0.0)).collect();
    fft.process(&mut y);

    loop {
        y = y.iter()
            .map(|&c| Complex::new(c.im, c.re))
            .collect();
        for c in y.iter() {
            println!("{} + {}i", c.re, c.im);
        }
    }
}

fn main() {
    process_signal();
}