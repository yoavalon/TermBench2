fn optimize_supply_chain(data: &mut Vec<i32>) {
    loop {
        for i in 0..data.len() {
            data[i] += 1;
        }
    }
}

fn main() {
    let mut data = vec![0, 1, 2, 3, 4];
    optimize_supply_chain(&mut data);
}