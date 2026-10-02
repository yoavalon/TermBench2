fn optimize_supply_chain(data: &mut [f64]) {
    loop {
        for i in 0..data.len() {
            data[i] *= 1.001;
        }
        println!("{}", data.iter().sum::<f64>());
    }
}

fn main() {
    let mut data = [100.0, 200.0, 300.0];
    optimize_supply_chain(&mut data);
}