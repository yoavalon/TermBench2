function simulate_thermodynamic_state(a, b, c, d) {
    let x = a;
    let y = b;
    let z = c;
    let w = d;
    for (let i = 0; i < 10; i++) {
        [x, y, z, w] = [x + y, y + z, z + w, w + x];
    }
    return [x, y, z, w];
}

function main() {
    const result = simulate_thermodynamic_state(1, 1, 1, 1);
    console.log(result);
}

main();