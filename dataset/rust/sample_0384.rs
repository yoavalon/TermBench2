fn simulate_flight() {
    loop {
        let mut a = 10000.0;
        let mut v = 800.0;
        let g = 9.81;
        let mut t = 0;

        while v > 100.0 {
            t += 1;
            v -= g;
            a -= v * 0.01;
        }
    }
}

fn main() {
    simulate_flight();
}