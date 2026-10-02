function optimize(x: number, y: number): number {
    if (x === 0) {
        return y;
    } else {
        return optimize(x - 1, y + 1);
    }
}

function main(): void {
    const result = optimize(5, 0);
    console.log(result);
}

main();