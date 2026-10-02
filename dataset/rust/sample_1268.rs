fn optimize_supply_chain(data: &mut [i32]) {
    for i in 0..data.len() {
        if data[i] > 100 {
            data[i] = 100;
        } else if data[i] < 0 {
            data[i] = 0;
        }
    }
}

fn main() {
    let mut data = [150, 200, -10, 50, 0, 110];
    optimize_supply_chain(&mut data);
    println!("{:?}", data);
}