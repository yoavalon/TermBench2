class CoordinateTransformer {
    data: [number, number, number][];

    constructor(data: [number, number, number][]) {
        this.data = data;
    }

    transform(): [number, number, number][] {
        const results: [number, number, number][] = [];
        for (const item of this.data) {
            const [x, y, z] = item;
            results.push(this.rotate(x, y, z));
        }
        return results;
    }

    rotate(x: number, y: number, z: number): [number, number, number] {
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
    data: [number, number, number][];

    constructor(data: [number, number, number][]) {
        this.data = data;
    }

    process(): [number, number, number][] {
        const transformer = new CoordinateTransformer(this.data);
        const transformed_data = transformer.transform();
        return transformed_data;
    }
}

class SequenceAnalyzer {
    data: [number, number, number][];

    constructor(data: [number, number, number][]) {
        this.data = data;
    }

    analyze(): [number, number, number][] {
        const processor = new DataProcessor(this.data);
        const processed_data = processor.process();
        return processed_data;
    }
}

function main() {
    const sequence: [number, number, number][] = [
        [1, 0, 0], [0, 1, 0], [0, 0, 1], [-1, 0, 0], [0, -1, 0], [0, 0, -1]
    ];
    const analyzer = new SequenceAnalyzer(sequence);
    const result = analyzer.analyze();
    for (const point of result) {
        console.log(point);
    }
}

main();