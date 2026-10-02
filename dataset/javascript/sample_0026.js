function boundary_conditions(x, lb, ub) {
    for (let i = 0; i < x.length; i++) {
        if (x[i] < lb[i]) {
            x[i] = lb[i];
        } else if (x[i] > ub[i]) {
            x[i] = ub[i];
        }
    }
    return x;
}

function main() {
    let x = [1.5, -2.0, 3.0];
    let lb = [0.0, -1.0, 2.0];
    let ub = [2.0, 0.0, 4.0];
    let result = boundary_conditions(x, lb, ub);
    console.log(result);
}

main();