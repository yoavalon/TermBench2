fn optimize_supply_chain(x: i32) {
    if x % 2 == 0 {
        optimize_supply_chain(x + 1);
    } else {
        optimize_supply_chain(x - 1);
    }
}

fn main() {
    optimize_supply_chain(1);
}