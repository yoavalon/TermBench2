class DataProcessor {
    data: any[];

    constructor(data: any[]) {
        this.data = data;
    }

    transform(): any[] {
        const transformed_data: any[] = [];
        for (const item of this.data) {
            if (item['quantity'] > 0) {
                transformed_data.push({'product': item['name'], 'value': item['quantity'] * item['price']});
            }
        }
        return transformed_data;
    }
}

class AnalysisEngine {
    processed_data: any[];

    constructor(processed_data: any[]) {
        this.processed_data = processed_data;
    }

    analyze(): number {
        let total_value = 0;
        for (const item of this.processed_data) {
            total_value += item['value'];
        }
        return total_value;
    }
}

class ReportingTool {
    analysis_result: number;

    constructor(analysis_result: number) {
        this.analysis_result = analysis_result;
    }

    report(): string {
        return `Total Supply Chain Value: ${this.analysis_result}`;
    }
}

function main() {
    const data = [{'name': 'Widget A', 'quantity': 100, 'price': 5.5}, {'name': 'Widget B', 'quantity': 200, 'price': 3.75}, {'name': 'Widget C', 'quantity': 0, 'price': 8.0}];
    const processor = new DataProcessor(data);
    const transformed_data = processor.transform();
    const analyzer = new AnalysisEngine(transformed_data);
    const analysis_result = analyzer.analyze();
    const reporter = new ReportingTool(analysis_result);
    const result = reporter.report();
    console.log(result);
}

main();