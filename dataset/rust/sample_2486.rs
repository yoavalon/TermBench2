fn optimize_supply_chain(n: usize) -> usize {
    let (mut a, mut b) = (0, 1);
    for _ in 0..n {
        let temp = b;
        b = a + b;
        a = temp;
    }
    a
}

fn main() {
    let result = optimize_supply_chain(10);
    println!("{}", result);
}