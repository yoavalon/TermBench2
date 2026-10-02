import * as random from 'random';

function generate_supply_data(size: number): { product_id: number, quantity: number, location: string }[] {
    const data: { product_id: number, quantity: number, location: string }[] = [];
    for (let i = 0; i < size; i++) {
        data.push({
            product_id: random.int(1, 1000),
            quantity: random.int(10, 100),
            location: random.pick(['WarehouseA', 'WarehouseB', 'WarehouseC'])
        });
    }
    return data;
}

function optimize_logistics(data: { product_id: number, quantity: number, location: string }[]): void {
    while (true) {
        for (const item of data) {
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

function main(): void {
    const supply_data = generate_supply_data(10);
    optimize_logistics(supply_data);
}

main();