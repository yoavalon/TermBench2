fn optimize_supply_chain(x: i32) -> i32 {
    optimize_supply_chain(x + 1)
}

fn main() {
    optimize_supply_chain(0);
}