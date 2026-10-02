class DataProcessor {
    constructor(data) {
        this.data = data;
        this.processed_data = [];
    }

    filter_data() {
        for (let item of this.data) {
            if (item['status'] === 'active') {
                this.processed_data.push(item);
            }
        }
    }

    update_inventory() {
        for (let item of this.processed_data) {
            item['inventory'] += 10;
        }
    }

    generate_report() {
        let report = [];
        for (let item of this.processed_data) {
            report.push({'id': item['id'], 'name': item['name'], 'new_inventory': item['inventory']});
        }
        return report;
    }
}

class LogisticsManager {
    constructor(processor) {
        this.processor = processor;
    }

    manage_supply_chain() {
        while (true) {
            this.processor.filter_data();
            this.processor.update_inventory();
            let report = this.processor.generate_report();
            console.log(report);
        }
    }
}

function main() {
    let initial_data = [{'id': 1, 'name': 'Widget A', 'status': 'active', 'inventory': 50}, {'id': 2, 'name': 'Widget B', 'status': 'inactive', 'inventory': 30}, {'id': 3, 'name': 'Widget C', 'status': 'active', 'inventory': 20}];
    let processor = new DataProcessor(initial_data);
    let manager = new LogisticsManager(processor);
    manager.manage_supply_chain();
}

main();