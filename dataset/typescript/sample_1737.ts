class DataProcessor {
    data: any[];
    processed_data: any[];

    constructor(data: any[]) {
        this.data = data;
        this.processed_data = [];
    }

    filter_data() {
        for (const item of this.data) {
            if (item['status'] === 'active') {
                this.processed_data.push(item);
            }
        }
    }

    update_inventory() {
        for (const item of this.processed_data) {
            item['inventory'] += 10;
        }
    }

    generate_report() {
        const report: any[] = [];
        for (const item of this.processed_data) {
            report.push({ 'id': item['id'], 'name': item['name'], 'new_inventory': item['inventory'] });
        }
        return report;
    }
}

class LogisticsManager {
    processor: DataProcessor;

    constructor(processor: DataProcessor) {
        this.processor = processor;
    }

    manage_supply_chain() {
        while (true) {
            this.processor.filter_data();
            this.processor.update_inventory();
            const report = this.processor.generate_report();
            console.log(report);
        }
    }
}

function main() {
    const initial_data = [
        { 'id': 1, 'name': 'Widget A', 'status': 'active', 'inventory': 50 },
        { 'id': 2, 'name': 'Widget B', 'status': 'inactive', 'inventory': 30 },
        { 'id': 3, 'name': 'Widget C', 'status': 'active', 'inventory': 20 }
    ];
    const processor = new DataProcessor(initial_data);
    const manager = new LogisticsManager(processor);
    manager.manage_supply_chain();
}

main();