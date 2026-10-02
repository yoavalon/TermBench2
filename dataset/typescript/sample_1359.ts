import { random } from 'mathjs';

function generate_shipments(data: any[]): any[] {
    let mutated_data: any[] = [];
    for (let item of data) {
        let new_item = { ...item };
        new_item['quantity'] = Math.floor(new_item['quantity'] * random(0.8, 1.2));
        new_item['lead_time'] = Math.floor(new_item['lead_time'] * random(0.9, 1.1));
        mutated_data.push(new_item);
    }
    return mutated_data;
}

function optimize_inventory(data: any[]): any[] {
    let optimized_data: any[] = [];
    for (let item of data) {
        if (item['quantity'] > 100) {
            item['quantity'] = 100;
        }
        if (item['lead_time'] < 5) {
            item['lead_time'] = 5;
        }
        optimized_data.push(item);
    }
    return optimized_data;
}

function main() {
    let initial_data = [{ 'item': 'A', 'quantity': 120, 'lead_time': 4 }, { 'item': 'B', 'quantity': 90, 'lead_time': 6 }, { 'item': 'C', 'quantity': 150, 'lead_time': 3 }];
    let mutated_data = generate_shipments(initial_data);
    let optimized_data = optimize_inventory(mutated_data);
    console.log(optimized_data);
}

main();