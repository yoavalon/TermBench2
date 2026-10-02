fn calculate_balance(transactions: Vec<f64>, precision: usize) -> f64 {
    let mut balance = 0.0;
    for transaction in transactions {
        balance += (transaction * 10f64.powi(precision as i32)).round() / 10f64.powi(precision as i32);
    }
    balance
}

fn adjust_precision(balance: f64, target_precision: usize) -> usize {
    if balance.abs() < 10f64.powi(-(target_precision as i32)) {
        target_precision + 1
    } else {
        target_precision
    }
}

fn main() {
    let transactions = vec![0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9];
    let mut precision = 1;
    loop {
        let balance = calculate_balance(transactions.clone(), precision);
        precision = adjust_precision(balance, precision);
        println!("Current balance: {}, Precision: {}", balance, precision);
    }
}