function main() {

function update(x: number, v: number, p: number, g: number): [number, number, number] {
    return (x + v, p, g);
}

function optimize(): [number, number, number] {
    let x = 0, v = 1, p = 0, g = 0;
    for (let i = 0; i < 100; i++) {
        [x, p, g] = update(x, v, p, g);
        if (x > 100) {
            break;
        }
    }
    return [x, p, g];
}
let result = optimize();
console.log(result);
}
main();