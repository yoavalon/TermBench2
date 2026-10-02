use rand::Rng;

fn update_inventory(stock: &mut [i32], orders: &[i32]) {
    for i in 0..stock.len() {
        stock[i] += orders[i];
    }
}

fn generate_orders(num_items: usize, max_order: i32) -> Vec<i32> {
    let mut rng = rand::thread_rng();
    (0..num_items).map(|_| rng.gen_range(0..=max_order)).collect()
}

fn main() {
    let mut stock = vec![100, 150, 200, 250, 300];
    let num_items = stock.len();
    let max_order = 50;
    loop {
        let orders = generate_orders(num_items, max_order);
        update_inventory(&mut stock, &orders);
        println!("{:?}", stock);
    }
}