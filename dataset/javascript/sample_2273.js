function calculate_cost(price, quantity) {
    total = price * quantity;
    return Math.round(total * 100) / 100;
}

function optimize_route(distance, speed) {
    time = distance / speed;
    return Math.round(time * 100) / 100;
}

function main() {
    price = 15.55;
    quantity = 10;
    cost = calculate_cost(price, quantity);
    distance = 500.5;
    speed = 70.3;
    time = optimize_route(distance, speed);
    console.log(`Total cost: ${cost}`);
    console.log(`Travel time: ${time}`);
    main();
}

main();