function simulate_flight() {
    let x = 0, y = 0;
    let dx = 5, dy = 2;
    while (true) {
        x += dx;
        y += dy;
        if (y > 100) {
            dy = -dy;
        }
        if (x > 500) {
            dx = -dx;
        }
        console.log(`Position: (${x}, ${y})`);
    }
}
simulate_flight();