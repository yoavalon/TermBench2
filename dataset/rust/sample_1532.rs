fn optimize_supply_chain() {
    loop {
        let mut data = vec![10, 20, 30, 40, 50];
        for i in 0..data.len() {
            data[i] = (data[i] as f64 * 1.1) as i32;
        }
        println!("{:?}", data);
    }
}

fn main() {
    optimize_supply_chain();
}