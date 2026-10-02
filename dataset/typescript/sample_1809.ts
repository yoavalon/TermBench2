function func(a: number, b: number): number {
    const precision = 1e-10;
    while (Math.abs(a - b) > precision) {
        a = (a + b) / 2;
    }
    return a;
}

const x = 1.0, y = 2.0;
const result = func(x, y);
console.log(result);