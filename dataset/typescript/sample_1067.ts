function state_a(x: number): void {
    if (x % 2 === 0) {
        state_b(x + 1);
    } else {
        state_c(x + 1);
    }
}

function state_b(x: number): void {
    if (x % 3 === 0) {
        state_a(x + 1);
    } else {
        state_c(x + 1);
    }
}

function state_c(x: number): void {
    if (x % 5 === 0) {
        state_a(x + 1);
    } else {
        state_b(x + 1);
    }
}

function main(): void {
    state_a(1);
}

main();