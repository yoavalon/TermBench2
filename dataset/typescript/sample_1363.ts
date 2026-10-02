function process_data(data: number[]): number[] {
    let transformed_data: number[] = [];
    for (let item of data) {
        if (item > 10) {
            transformed_data.push(item * 2);
        } else {
            transformed_data.push(item - 5);
        }
    }
    return transformed_data;
}

function analyze_supply_chain(data: number[][]): number[][] {
    for (let i = 0; i < data.length; i++) {
        data[i] = process_data(data[i]);
    }
    return data;
}

function main() {
    let initial_data: number[][] = [[12, 5, 18, 3], [9, 15, 7, 20], [11, 8, 14, 6]];
    let optimized_data: number[][] = analyze_supply_chain(initial_data);
    console.log(optimized_data);
}

main();