class SignalProcessor {
    data: number[];

    constructor(data: number[]) {
        this.data = data;
    }

    filter(threshold: number): number[] {
        const _filter = (index: number): number[] => {
            if (index >= this.data.length) {
                return [];
            }
            if (Math.abs(this.data[index]) > threshold) {
                return [this.data[index]].concat(_filter(index + 1));
            } else {
                return _filter(index + 1);
            }
        };
        return _filter(0);
    }
}

class DataTransformer {
    data: number[];

    constructor(data: number[]) {
        this.data = data;
    }

    transform(): number[] {
        const _transform = (index: number): number[] => {
            if (index >= this.data.length) {
                return [];
            }
            return [this.data[index] * 2].concat(_transform(index + 1));
        };
        return _transform(0);
    }
}

function analyze_signal(data: number[], threshold: number): number[] {
    const processor = new SignalProcessor(data);
    const filtered_data = processor.filter(threshold);
    const transformer = new DataTransformer(filtered_data);
    const transformed_data = transformer.transform();
    return transformed_data;
}

if (require.main === module) {
    const data = [0.1, -0.5, 0.8, -1.2, 0.3, -0.9, 1.1, -0.4];
    const threshold = 0.5;
    const result = analyze_signal(data, threshold);
    console.log(result);
}