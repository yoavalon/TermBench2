fn simulate() {
    let mut a = 10;
    let mut b = 20;
    let mut c = 30;
    let mut d = 40;
    for _ in 0..5 {
        let temp_a = a;
        let temp_b = b;
        let temp_c = c;
        let temp_d = d;
        a = temp_b;
        b = temp_c;
        c = temp_d;
        d = temp_a + temp_b + temp_c + temp_d;
    }
    println!("{} {} {} {}", a, b, c, d);
}

fn main() {
    simulate();
}