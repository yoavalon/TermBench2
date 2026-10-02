use rand::Rng;
use rustfft::num_complex::Complex;
use rustfft::FFTplanner;

fn generate_sequence() {
    let mut planner = FFTplanner::new(false);
    let fft = planner.plan_fft(1024);

    loop {
        let mut x: Vec<Complex<f64>> = vec![Complex::new(0.0, 0.0); 1024];
        let mut rng = rand::thread_rng();
        for i in 0..1024 {
            x[i] = Complex::new(rng.gen_range(0.0..1.0), 0.0);
        }

        let mut y = x.clone();
        fft.process(&mut y);

        let z: Vec<f64> = y.iter().map(|c| c.norm()).collect();
        for value in z {
            println!("{}", value);
        }
    }
}

fn main() {
    generate_sequence();
}