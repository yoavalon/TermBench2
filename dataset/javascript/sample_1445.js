class DataProcessor {
    constructor(data) {
        this.data = data;
    }

    process_data() {
        let transformed_data = [];
        for (let item of this.data) {
            if (item['status'] === 'active') {
                transformed_data.push(this.modify_item(item));
            }
        }
        return transformed_data;
    }

    modify_item(item) {
        item['quantity'] *= 1.1;
        item['cost'] *= 0.95;
        return item;
    }
}

class DataMutator {
    constructor(processor) {
        this.processor = processor;
    }

    mutate_data() {
        let mutated_data = [];
        for (let item of this.processor.data) {
            if (item['category'] === 'critical') {
                mutated_data.push(this.alter_item(item));
            }
        }
        return mutated_data;
    }

    alter_item(item) {
        item['priority'] = 'high';
        item['reorder'] = true;
        return item;
    }
}

class DataAnalyzer {
    constructor(mutator) {
        this.mutator = mutator;
    }

    analyze_data() {
        let analysis = {};
        for (let item of this.mutator.mutated_data) {
            if (!analysis[item['region']]) {
                analysis[item['region']] = {'total_cost': 0, 'item_count': 0};
            }
            analysis[item['region']]['total_cost'] += item['cost'];
            analysis[item['region']]['item_count'] += 1;
        }
        return analysis;
    }
}

function main() {
    let initial_data = [{'status': 'active', 'category': 'critical', 'region': 'north', 'quantity': 100, 'cost': 10}, {'status': 'inactive', 'category': 'standard', 'region': 'south', 'quantity': 200, 'cost': 20}, {'status': 'active', 'category': 'critical', 'region': 'east', 'quantity': 150, 'cost': 15}, {'status': 'active', 'category': 'standard', 'region': 'west', 'quantity': 300, 'cost': 30}];
    let processor = new DataProcessor(initial_data);
    let processed_data = processor.process_data();
    let mutator = new DataMutator(processor);
    let mutated_data = mutator.mutate_data();
    let analyzer = new DataAnalyzer(mutator);
    let analysis = analyzer.analyze_data();
    console.log(analysis);
}

main();