function optimize_supply_chain(n) {
    let a = 0, b = 1;
    for (let i = 0; i < n; i++) {
        [a, b] = [b, a + b];
    }
    return a;
}
const result = optimize_supply_chain(10);
console.log(result);