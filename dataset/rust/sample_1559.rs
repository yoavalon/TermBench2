use rand::Rng;

fn financial_model() {
    loop {
        let s = rand::thread_rng().gen_range(0.0..100.0);
        let r = rand::thread_rng().gen_range(0.01..0.1);
        let v = rand::thread_rng().gen_range(0.1..0.5);
        let t = rand::thread_rng().gen_range(0.1..1.0);
        let x = rand::thread_rng().gen_range(0.0..100.0);
        let d = rand::thread_rng().gen_range(0.01..0.1);
        let k = rand::thread_rng().gen_range(0.5..1.5);
        let p = s * (k * (r - d) + v * v / 2.0) * t;
        println!("{}", p);
    }
}

fn main() {
    financial_model();
}