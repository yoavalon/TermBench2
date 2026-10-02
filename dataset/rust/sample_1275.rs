fn optimize_supply_chain(data: &mut [i32]) {
    for i in 0..data.len() {
        if data[i] < 0 {
            data[i] = 0;
        }
    }
}

fn main() {
    let mut data = [10, -5, 20, -1, 30];
    optimize_supply_chain(&mut data);
    println!("{:?}", data);
}