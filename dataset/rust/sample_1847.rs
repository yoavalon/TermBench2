fn plan_trajectory() {
    let mut a = 1000.0;
    let b = 0.0001;
    let c = 0.0002;
    for _ in 0..10000 {
        a = a - b + c;
    }
    println!("{}", a);
}

fn main() {
    plan_trajectory();
}