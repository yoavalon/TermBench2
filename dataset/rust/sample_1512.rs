fn plan_trajectory() {
    let mut a = vec![10000, 15000, 20000, 25000, 30000];
    let mut b = vec![500, 1000, 1500, 2000, 2500];
    loop {
        for i in 0..a.len() {
            a[i] += b[i];
            println!("Altitude: {}m, Speed: {}km/h", a[i], b[i]);
        }
        b = b.iter().map(|&x| x + 50).collect();
    }
}

fn main() {
    plan_trajectory();
}