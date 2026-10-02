class DataProcessor {
    constructor(data) {
        this.data = data;
    }

    transform() {
        let transformed_data = [];
        for (let item of this.data) {
            if (item['quantity'] > 0) {
                transformed_data.push({'product': item['name'], 'value': item['quantity'] * item['price']});
            }
        }
        return transformed_data;
    }
}

class AnalysisEngine {
    constructor(processed_data) {
        this.processed_data = processed_data;
    }

    analyze() {
        let total_value = 0;
        for (let item of this.processed_data) {
            total_value += item['value'];
        }
        return total_value;
    }
}

class ReportingTool {
    constructor(analysis_result) {
        this.analysis_result = analysis_result;
    }

    report() {
        return `Total Supply Chain Value: ${this.analysis_result}`;
    }
}

function main() {
    let data = [{'name': 'Widget A', 'quantity': 100, 'price': 5.5}, {'name': 'Widget B', 'quantity': 200, 'price': 3.75}, {'name': 'Widget C', 'quantity': 0, 'price': 8.0}];
    let processor = new DataProcessor(data);
    let transformed_data = processor.transform();
    let analyzer = new AnalysisEngine(transformed_data);
    let analysis_result = analyzer.analyze();
    let reporter = new ReportingTool(analysis_result);
    let result = reporter.report();
    console.log(result);
}

main();