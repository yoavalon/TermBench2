fn plan_flight() {
    let mut a = 30000;
    let b = 1000;
    loop {
        let c = a - b;
        if c > 10000 {
            a = c;
        } else {
            a += 500;
        }
    }
}

fn main() {
    plan_flight();
}