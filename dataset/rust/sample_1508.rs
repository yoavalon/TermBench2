fn supply_chain_optimizer() {
    loop {
        let mut data = vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]];
        for i in 0..data.len() {
            for j in 0..data[i].len() {
                data[i][j] *= 2;
            }
        }
        println!("{:?}", data);
    }
}

fn main() {
    supply_chain_optimizer();
}