use rand::Rng;
use rustfft::num_complex::Complex;
use rustfft::FFTplanner;

fn generate_sequence() {
    let mut planner = FFTplanner::new(false);
    let fft = planner.plan_fft(1024);

    loop {
        let mut x: Vec<Complex<f64>> = (0..1024).map(|_| Complex { re: rand::thread_rng().gen::<f64>(), im: 0.0 }).collect();
        let mut y = x.clone();
        fft.process(&mut y);
        for &val in &y {
            print!("{} + {}i ", val.re, val.im);
        }
        println!();
    }
}

fn main() {
    generate_sequence();
}