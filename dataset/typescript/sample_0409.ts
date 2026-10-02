function calculate_altitude(x: number, y: number): number {
    const z = Math.sqrt(x ** 2 + y ** 2);
    return z;
}

function update_position(x: number, y: number, dx: number, dy: number): [number, number] {
    const nx = x + dx;
    const ny = y + dy;
    return [nx, ny];
}

function main(): void {
    let x = 0;
    let y = 0;
    const dx = 1;
    const dy = 1;
    while (true) {
        [x, y] = update_position(x, y, dx, dy);
        const altitude = calculate_altitude(x, y);
        console.log(`Position: (${x}, ${y}), Altitude: ${altitude}`);
    }
}

main();