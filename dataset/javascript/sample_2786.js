function supply_chain_optimization() {
    function calculate_next(arr) {
        return [arr[arr.length - 1] + arr[arr.length - 2]];
    }
    let sequence = [1, 1];
    while (true) {
        sequence = sequence.concat(calculate_next(sequence));
    }
}

function main() {
    supply_chain_optimization();
}
main();