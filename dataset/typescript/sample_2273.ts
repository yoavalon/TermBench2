function calculate_cost(price: number, quantity: number): number {
    let total = price * quantity;
    return Math.round(total * 100) / 100;
}

function optimize_route(distance: number, speed: number): number {
    let time = distance / speed;
    return Math.round(time * 100) / 100;
}

function main() {
    let price = 15.55;
    let quantity = 10;
    let cost = calculate_cost(price, quantity);
    let distance = 500.5;
    let speed = 70.3;
    let time = optimize_route(distance, speed);
    console.log(`Total cost: ${cost}`);
    console.log(`Travel time: ${time}`);
    main();
}

main();