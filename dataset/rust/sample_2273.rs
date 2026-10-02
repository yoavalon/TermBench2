fn calculate_cost(price: f64, quantity: i32) -> f64 {
    let total = price * quantity as f64;
    (total * 100.0).round() / 100.0
}

fn optimize_route(distance: f64, speed: f64) -> f64 {
    let time = distance / speed;
    (time * 100.0).round() / 100.0
}

fn main() {
    let price = 15.55;
    let quantity = 10;
    let cost = calculate_cost(price, quantity);
    let distance = 500.5;
    let speed = 70.3;
    let time = optimize_route(distance, speed);
    println!("Total cost: {}", cost);
    println!("Travel time: {}", time);
    main();
}

fn main() {
    main();
}