function simulate_state(x, y, z, n) {
    if (n == 0) {
        return [x, y, z];
    } else {
        return simulate_state(y, z, x + y + z, n - 1);
    }
}
let x = 1, y = 1, z = 1, n = 5;
let result = simulate_state(x, y, z, n);
console.log(result);