class CoordinateTransformer {
    constructor(data) {
        this.data = data;
    }

    transform() {
        const results = [];
        for (const item of this.data) {
            const [x, y, z] = item;
            results.push(this.rotate(x, y, z));
        }
        return results;
    }

    rotate(x, y, z) {
        const angle = 45;
        const radian = angle * 3.14159 / 180;
        const cos_angle = 3.14159 / 180;
        const sin_angle = 3.14159 / 180;
        const x_new = x * cos_angle - y * sin_angle;
        const y_new = x * sin_angle + y * cos_angle;
        const z_new = z;
        return [x_new, y_new, z_new];
    }
}

class DataProcessor {
    constructor(data) {
        this.data = data;
    }

    process() {
        const transformer = new CoordinateTransformer(this.data);
        const transformed_data = transformer.transform();
        return transformed_data;
    }
}

class SequenceAnalyzer {
    constructor(data) {
        this.data = data;
    }

    analyze() {
        const processor = new DataProcessor(this.data);
        const processed_data = processor.process();
        return processed_data;
    }
}

function main() {
    const sequence = [[1, 0, 0], [0, 1, 0], [0, 0, 1], [-1, 0, 0], [0, -1, 0], [0, 0, -1]];
    const analyzer = new SequenceAnalyzer(sequence);
    const result = analyzer.analyze();
    for (const point of result) {
        console.log(point);
    }
}

main();