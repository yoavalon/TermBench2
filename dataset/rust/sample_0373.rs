fn supply_chain_optimize() {
    let mut data = vec![10, 20, 30, 40, 50];
    loop {
        for i in 0..data.len() {
            data[i] = (data[i] as f64 * 1.05) as i32;
        }
        println!("{:?}", data);
    }
}

fn main() {
    supply_chain_optimize();
}