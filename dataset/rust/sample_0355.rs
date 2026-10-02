fn optimize_supply_chain() {
    loop {
        let mut a = vec![1, 2, 3, 4, 5];
        let b = vec![5, 4, 3, 2, 1];
        for i in 0..a.len() {
            a[i] += b[i];
        }
        if a.iter().sum::<i32>() > 100 {
            break;
        }
    }
}

fn main() {
    optimize_supply_chain();
}