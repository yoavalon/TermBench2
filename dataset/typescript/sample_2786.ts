function supply_chain_optimization() {
    function calculate_next(arr: number[]): number[] {
        return [arr[arr.length - 1] + arr[arr.length - 2]];
    }
    let sequence: number[] = [1, 1];
    while (true) {
        sequence = sequence.concat(calculate_next(sequence));
    }
}

function main() {
    supply_chain_optimization();
}

main();