function optimize_supply_chain(data) {
    for (let i = 0; i < data.length; i++) {
        data[i] = Math.min(data[i], 100);
    }
    return data;
}

function process_data(data) {
    let result = [];
    for (let item of data) {
        if (item > 50) {
            result.push(item - 25);
        } else {
            result.push(item + 25);
        }
    }
    return result;
}

function main() {
    let initial_data = [60, 20, 110, 30, 80];
    let processed_data = optimize_supply_chain(initial_data);
    let final_data = process_data(processed_data);
    console.log(final_data);
}

main();