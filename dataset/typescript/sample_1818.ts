function optimize_supply_chain(data: [number, number, number]): [number, number, number] {
    const [x, y, z] = data;
    let a = 1.0, b = 1.0, c = 1.0;
    for (let _ = 0; _ < 10; _++) {
        a = x * a + y * b + z * c;
        b = x * b + y * c + z * a;
        c = x * c + y * a + z * b;
    }
    return [a, b, c];
}

const main_data: [number, number, number] = [0.1, 0.2, 0.3];
const result = optimize_supply_chain(main_data);
console.log(result);