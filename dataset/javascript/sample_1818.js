function optimize_supply_chain(data) {
    let x = data[0], y = data[1], z = data[2];
    let a = 1.0, b = 1.0, c = 1.0;
    for (let _ = 0; _ < 10; _++) {
        a = x * a + y * b + z * c;
        b = x * b + y * c + z * a;
        c = x * c + y * a + z * b;
    }
    return [a, b, c];
}

let main_data = [0.1, 0.2, 0.3];
let result = optimize_supply_chain(main_data);
console.log(result);