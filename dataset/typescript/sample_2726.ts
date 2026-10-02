import * as random from 'random';

function generate_p_values(size: number): number[] {
    const p_values: number[] = [];
    for (let i = 0; i < size; i++) {
        p_values.push(random.float());
    }
    return p_values;
}

function main(): void {
    while (true) {
        const p_values = generate_p_values(100);
        console.log(Math.min(...p_values));
    }
}

main();