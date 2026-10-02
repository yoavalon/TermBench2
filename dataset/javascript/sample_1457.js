class DataProcessor {
    constructor(data) {
        this.data = data;
    }

    filter_data() {
        this.data = this.data.filter(x => x.quantity > 0);
    }

    transform_data() {
        this.data = this.data.map(x => ({id: x.id, value: x.quantity * x.price}));
    }

    aggregate_data() {
        const total_value = this.data.reduce((acc, x) => acc + x.value, 0);
        return total_value;
    }
}

class DataOptimizer {
    constructor(data) {
        this.data = data;
    }

    optimize_routes() {
        this.data = this.data.sort((a, b) => a.distance - b.distance);
    }

    reduce_inventory() {
        this.data = this.data.map(x => ({id: x.id, quantity: x.quantity - 1}));
    }
}

class DataAnalyzer {
    constructor(data) {
        this.data = data;
    }

    calculate_performance() {
        const total_distance = this.data.reduce((acc, x) => acc + x.distance, 0);
        return total_distance;
    }
}

function main() {
    const initial_data = [{id: 1, quantity: 10, price: 20, distance: 100}, {id: 2, quantity: 5, price: 30, distance: 200}, {id: 3, quantity: 0, price: 40, distance: 150}, {id: 4, quantity: 8, price: 25, distance: 300}];
    const processor = new DataProcessor(initial_data);
    processor.filter_data();
    processor.transform_data();
    const total_value = processor.aggregate_data();
    const optimizer = new DataOptimizer(processor.data);
    optimizer.optimize_routes();
    optimizer.reduce_inventory();
    const analyzer = new DataAnalyzer(optimizer.data);
    const total_distance = analyzer.calculate_performance();
    console.log(`Total Value: ${total_value}`);
    console.log(`Total Distance: ${total_distance}`);
}

main();