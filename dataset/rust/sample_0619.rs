fn optimize_supply_chain(n: i32, a: i32, b: i32) -> i32 {
    if n == 0 {
        0
    } else if n == 1 {
        a
    } else {
        optimize_supply_chain(n - 1, a, b) + b
    }
}

fn main() {
    optimize_supply_chain(5, 10, 2);
}