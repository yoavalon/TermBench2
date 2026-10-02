function calculate_altitude(x, y) {
    var z = Math.sqrt(x ** 2 + y ** 2);
    return z;
}

function update_position(x, y, dx, dy) {
    var nx = x + dx;
    var ny = y + dy;
    return [nx, ny];
}

function main() {
    var x = 0, y = 0;
    var dx = 1, dy = 1;
    while (true) {
        var position = update_position(x, y, dx, dy);
        x = position[0];
        y = position[1];
        var altitude = calculate_altitude(x, y);
        console.log(`Position: (${x}, ${y}), Altitude: ${altitude}`);
    }
}

main();