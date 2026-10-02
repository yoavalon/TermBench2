fn optimize_supply_chain(x: i32, y: i32) {
    if x > y {
        optimize_supply_chain(x - 1, y);
    } else if x < y {
        optimize_supply_chain(x, y - 1);
    } else {
        optimize_supply_chain(x + 1, y + 1);
    }
}

fn main() {
    optimize_supply_chain(1, 1);
}