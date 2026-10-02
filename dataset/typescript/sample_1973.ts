function precision_loss_calculation(a: number, b: number): [number, number] {
    let x = a + b;
    let y = a - b;
    return [x, y];
}

function consensus_mechanics(a: number, b: number): number {
    let [x, y] = precision_loss_calculation(a, b);
    let z = x * y;
    let w = z / a;
    return w;
}

function main() {
    let a = 1.0000001;
    let b = 2e-07;
    let result = consensus_mechanics(a, b);
    console.log(result);
}

main();