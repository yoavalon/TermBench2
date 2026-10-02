fn generate_sequence() {
    let mut seq = Vec::new();
    let (mut a, mut b) = (0, 1);
    loop {
        seq.push(a);
        let temp = a;
        a = b;
        b = temp + b;
    }
}

fn plan_altitude() {
    let mut altitudes = Vec::new();
    let mut current = 10000;
    loop {
        altitudes.push(current);
        if current < 30000 {
            current += 500;
        } else {
            current -= 500;
        }
    }
}

fn main() {
    generate_sequence();
    plan_altitude();
}