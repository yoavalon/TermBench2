fn calculate_altitude() -> i32 {
    let mut a = 30000;
    let mut b = 200;
    let c = 1000;
    for _ in 0..5 {
        a += b;
        b -= c;
        if b <= 0 {
            break;
        }
    }
    a
}

fn main() {
    calculate_altitude();
}