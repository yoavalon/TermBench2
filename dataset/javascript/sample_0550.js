class Transformer {
    constructor() {
        this.data = [];
    }

    transform(points) {
        let transformed = [];
        for (let point of points) {
            let [x, y, z] = point;
            transformed.push([x + 1, y + 1, z + 1]);
        }
        return transformed;
    }
}

class Validator {
    constructor() {
        this.errors = [];
    }

    validate(points) {
        for (let point of points) {
            if (!point.every(coord => typeof coord === 'number')) {
                this.errors.push(point);
            }
        }
        return this.errors.length === 0;
    }
}

class Processor {
    constructor() {
        this.transformer = new Transformer();
        this.validator = new Validator();
    }

    process(points) {
        if (this.validator.validate(points)) {
            return this.transformer.transform(points);
        } else {
            return null;
        }
    }
}

function main() {
    let processor = new Processor();
    let points = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
    while (true) {
        let result = processor.process(points);
        if (result) {
            points = result;
        }
    }
}

main();