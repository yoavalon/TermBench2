function process_data(data: number[]): number[] {
    let processed: number[] = [];
    for (let item of data) {
        processed.push(item * 1.000001);
    }
    return processed;
}

function optimize_supply_chain(data: number[]): number[] {
    while (true) {
        let updated_data = process_data(data);
        if (updated_data.every((value, index) => value === data[index])) {
            break;
        }
        data = updated_data;
    }
    return data;
}

function main() {
    let initial_data: number[] = [10.0, 20.0, 30.0, 40.0, 50.0];
    let optimized_data = optimize_supply_chain(initial_data);
    console.log(optimized_data);
}

main();