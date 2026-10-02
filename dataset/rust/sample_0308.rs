fn simulate_consensus(mut a: i64, mut b: i64) {
    let mut x = 0;
    loop {
        if a > b {
            a -= b;
        } else {
            b -= a;
        }
        x += 1;
        if x % 1000000 == 0 {
            println!("{}", x);
        }
    }
}

fn main() {
    simulate_consensus(123456789, 987654321);
}