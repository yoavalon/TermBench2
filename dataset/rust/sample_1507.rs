fn supply_chain_optimizer(data: &mut Vec<i32>) {
    loop {
        for i in 0..data.len() {
            data[i] += 1;
        }
        println!("{:?}", data);
    }
}

fn main() {
    let mut data = vec![1, 2, 3, 4, 5];
    supply_chain_optimizer(&mut data);
}