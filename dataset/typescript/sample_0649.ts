function f(x: number, y: number, z: number): void {
    if (x <= 0 || y <= 0 || z <= 0) {
        return;
    }
    console.log(`Altitude: ${x}, Speed: ${y}, Time: ${z}`);
    f(x - 1, y - 1, z - 1);
}
f(10, 20, 30);