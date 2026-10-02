fn optimize_supply_chain(demand: i32, supply: i32, max_iterations: i32) -> i32 {
    let mut supply = supply;
    for _ in 0..max_iterations {
        if demand > supply {
            supply += 1;
        } else if demand < supply {
            supply -= 1;
        } else {
            break;
        }
    }
    supply
}

fn main() {
    let result = optimize_supply_chain(100, 90, 10);
    println!("{}", result);
}