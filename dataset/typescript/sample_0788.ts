function optimize_shipments(data: number[], index: number): number[] {
    if (index >= data.length) {
        return [];
    }
    const current = data[index];
    const rest = optimize_shipments(data, index + 1);
    if (current < 10) {
        return [current, ...rest];
    } else {
        return rest;
    }
}

function process_data(data: number[]): number[] {
    return optimize_shipments(data, 0);
}

function main() {
    const data = [5, 12, 7, 9, 15, 3];
    const result = process_data(data);
    console.log(result);
}

main();