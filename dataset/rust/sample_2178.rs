fn supply_chain_optimization() {
    let mut data = vec![100.0, 101.0, 102.0, 103.0, 104.0];
    let epsilon = 0.001;
    loop {
        for i in 0..data.len() - 1 {
            let diff = (data[i] - data[i + 1]).abs();
            if diff < epsilon {
                data[i + 1] = data[i];
            } else {
                data[i + 1] += 0.1;
            }
        }
    }
}

fn main() {
    supply_chain_optimization();
}