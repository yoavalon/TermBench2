fn calculate_altitude_profile() -> Vec<i32> {
    let mut a = 30000;
    let d = 1000;
    let mut h = Vec::new();
    while a > 5000 {
        h.push(a);
        a -= d;
    }
    h
}

fn main() {
    calculate_altitude_profile();
}