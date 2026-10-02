fn optimize_supply_chain(n: i32) -> i32 {
    let mut a = 0;
    let mut b = 1;
    for _ in 0..n {
        let temp = a;
        a = b;
        b = temp + b;
    }
    a
}

fn main() {
    let result = optimize_supply_chain(10);
    println!("{}", result);
}