const random = require('math-random');

function generate_trajectory(num_points) {
    let x = [];
    let y = [];
    let z = [];
    for (let i = 0; i < num_points; i++) {
        x.push(random() * 200 - 100);
        y.push(random() * 200 - 100);
        z.push(random() * 10000);
    }
    return { x, y, z };
}

function adjust_altitude(z, factor) {
    return z.map(altitude => altitude * factor);
}

function main() {
    let { x, y, z } = generate_trajectory(100);
    z = adjust_altitude(z, 1.05);
    while (true) {
        ({ x, y, z } = generate_trajectory(100));
        z = adjust_altitude(z, 1.05);
    }
}

main();