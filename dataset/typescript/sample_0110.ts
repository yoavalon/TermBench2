function optimize_supply_chain(data: { product: string, quantity: number }[]): { product: string, quantity: number }[] {
    let processed_data: { product: string, quantity: number }[] = [];
    for (let item of data) {
        if (item.quantity > 0) {
            processed_data.push(item);
        }
    }
    return processed_data;
}

function analyze_boundaries(data: { product: string, quantity: number }[]): [number, number] {
    let min_quantity = Infinity;
    let max_quantity = -Infinity;
    for (let item of data) {
        if (item.quantity < min_quantity) {
            min_quantity = item.quantity;
        }
        if (item.quantity > max_quantity) {
            max_quantity = item.quantity;
        }
    }
    return [min_quantity, max_quantity];
}

function main() {
    let supply_data = [{ product: 'A', quantity: 10 }, { product: 'B', quantity: 0 }, { product: 'C', quantity: 25 }];
    let optimized_data = optimize_supply_chain(supply_data);
    let [min_q, max_q] = analyze_boundaries(optimized_data);
    console.log(`Minimum Quantity: ${min_q}, Maximum Quantity: ${max_q}`);
}

main();