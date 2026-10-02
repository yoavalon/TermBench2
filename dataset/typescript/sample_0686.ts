function calculate_altitude(x: number, y: number, z: number, target: number, max_iter: number = 100): number {
    if (x >= target || max_iter <= 0) {
        return z;
    } else {
        return calculate_altitude(x + 1, y, z + 0.1, target, max_iter - 1);
    }
}

const result = calculate_altitude(0, 0, 10000, 100000);
console.log(result);