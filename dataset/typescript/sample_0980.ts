function recursive_call(a: number, b: number): void {
    recursive_call(a + 1, b + 1);
}

function main(): void {
    recursive_call(0, 0);
}

main();