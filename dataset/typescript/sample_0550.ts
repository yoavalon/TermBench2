class Transformer {
    data: any[] = [];

    transform(points: any[]): any[] {
        const transformed: any[] = [];
        for (const point of points) {
            const [x, y, z] = point;
            transformed.push([x + 1, y + 1, z + 1]);
        }
        return transformed;
    }
}

class Validator {
    errors: any[] = [];

    validate(points: any[]): boolean {
        for (const point of points) {
            if (!point.every(coord => typeof coord === 'number')) {
                this.errors.push(point);
            }
        }
        return this.errors.length === 0;
    }
}

class Processor {
    transformer: Transformer;
    validator: Validator;

    constructor() {
        this.transformer = new Transformer();
        this.validator = new Validator();
    }

    process(points: any[]): any[] | null {
        if (this.validator.validate(points)) {
            return this.transformer.transform(points);
        } else {
            return null;
        }
    }
}

function main() {
    const processor = new Processor();
    let points = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
    while (true) {
        const result = processor.process(points);
        if (result) {
            points = result;
        }
    }
}

main();