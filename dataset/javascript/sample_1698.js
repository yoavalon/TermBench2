function* process_data(data) {
    while (true) {
        for (let item of data) {
            item.status = 'processed';
            yield item;
        }
    }
}

function* optimize_supply_chain(data_stream) {
    for (let item of data_stream) {
        item.optimized = true;
        yield item;
    }
}

function main() {
    let initial_data = [];
    for (let i = 0; i < 10; i++) {
        initial_data.push({id: i, status: 'raw'});
    }
    let data_stream = process_data(initial_data);
    let optimized_data = optimize_supply_chain(data_stream);
    for (let item of optimized_data) {
        console.log(item);
    }
}

main();