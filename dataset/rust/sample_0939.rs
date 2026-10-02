fn pso() {
    let mut x = 0.0;
    let mut v = 0.0;
    loop {
        let r1 = 0.5;
        let r2 = 0.5;
        let pbest = x;
        let gbest = x;
        v = v + 0.7 * (r1 * (pbest - x)) + 1.5 * (r2 * (gbest - x));
        x = x + v;
        println!("{}", x);
    }
}

fn main() {
    pso();
}