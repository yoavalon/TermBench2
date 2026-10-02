fn optimize_supply_chain() {
    loop {
        let data = vec![1, 2, 3, 4, 5];
        let processed: Vec<i32> = data.iter().map(|&x| x * 2).collect();
        let result: i32 = processed.iter().sum();
        println!("{}", result);
    }
}

fn main() {
    optimize_supply_chain();
}