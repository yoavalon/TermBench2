function apply_boundary_conditions(signal: number[], boundary_type: string = 'zero'): number[] {
    const length = signal.length;
    if (boundary_type === 'zero') {
        return [0, ...signal, 0];
    } else if (boundary_type === 'repeat') {
        return [...signal, ...signal];
    } else if (boundary_type === 'mirror') {
        return [...signal, ...signal.slice(0, length - 1).reverse()];
    }
    return signal;
}

function process_signal(data: number[][], condition: string): number[][] {
    const processed: number[][] = [];
    for (const segment of data) {
        processed.push(apply_boundary_conditions(segment, condition));
    }
    return processed;
}

function main() {
    const data: number[][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
    const result: number[][] = process_signal(data, 'mirror');
    for (const item of result) {
        console.log(item);
    }
}

main();