function* process_data(data: any[]): Generator<any, void, undefined> {
    while (true) {
        for (const item of data) {
            item['status'] = 'processed';
            yield item;
        }
    }
}

function* optimize_supply_chain(data_stream: Generator<any, void, undefined>): Generator<any, void, undefined> {
    for (const item of data_stream) {
        item['optimized'] = true;
        yield item;
    }
}

function main() {
    const initial_data = Array.from({ length: 10 }, (_, i) => ({ id: i, status: 'raw' }));
    const data_stream = process_data(initial_data);
    const optimized_data = optimize_supply_chain(data_stream);
    for (const item of optimized_data) {
        console.log(item);
    }
}

main();