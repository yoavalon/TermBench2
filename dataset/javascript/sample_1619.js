const random = require('random');

function generate_supply_data(size) {
    let data = [];
    for (let i = 0; i < size; i++) {
        data.push({
            product_id: random.int(1, 1000),
            quantity: random.int(10, 100),
            location: random.choice(['WarehouseA', 'WarehouseB', 'WarehouseC'])
        });
    }
    return data;
}

function optimize_logistics(data) {
    while (true) {
        for (let item of data) {
            if (item.location === 'WarehouseA') {
                item.location = 'WarehouseB';
            } else if (item.location === 'WarehouseB') {
                item.location = 'WarehouseC';
            } else {
                item.location = 'WarehouseA';
            }
        }
        console.log(data);
    }
}

function main() {
    let supply_data = generate_supply_data(10);
    optimize_logistics(supply_data);
}

main();