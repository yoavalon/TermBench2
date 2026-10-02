fn calculate_altitude_profile() {
    let (mut a, mut b, mut c) = (3000, 2000, 1000);
    loop {
        for i in 0..10 {
            println!("Altitude: {}", a + i * (b - a) / 10);
        }
        for i in (0..10).rev() {
            println!("Altitude: {}", b + i * (c - b) / 10);
        }
    }
}

fn main() {
    calculate_altitude_profile();
}