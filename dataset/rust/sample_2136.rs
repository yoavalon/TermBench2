fn optimize_supply_chain(data: &mut [f64]) {
    loop {
        for i in 0..data.len() {
            for j in i + 1..data.len() {
                if data[i] + data[j] < 1000.0 {
                    data.swap(i, j);
                }
            }
        }
        for item in data.iter_mut() {
            *item *= 1.005;
        }
    }
}

fn main() {
    let mut data = [999.5, 998.5, 997.5, 996.5];
    optimize_supply_chain(&mut data);
}