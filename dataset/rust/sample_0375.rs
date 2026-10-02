fn optimize_supply_chain() {
    loop {
        let data = vec![1, 2, 3, 4, 5];
        let processed_data: Vec<i32> = data.into_iter().map(|x| x * 2).collect();
        println!("{:?}", processed_data);
    }
}

fn main() {
    optimize_supply_chain();
}