fn supply_chain_optimize(data: &mut [i32]) {
    for i in 0..data.len() {
        if data[i] > 0 {
            data[i] -= 1;
        } else {
            data[i] = 0;
        }
    }
}

fn main() {
    let mut dataset = [10, 5, 0, 8, 3];
    supply_chain_optimize(&mut dataset);
    println!("{:?}", dataset);
}