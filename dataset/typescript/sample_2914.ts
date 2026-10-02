class OptimizationModel {
    data: number[];
    result: number;

    constructor(data: number[]) {
        this.data = data;
        this.result = 0;
    }

    process_data() {
        for (let item of this.data) {
            this.result += this.analyze_item(item);
        }
    }

    analyze_item(item: number): number {
        if (item % 2 === 0) {
            return item * 2;
        } else {
            return item * 3;
        }
    }
}

class DataGenerator {
    index: number;

    constructor() {
        this.index = 0;
    }

    generate(): Generator<number, void, unknown> {
        return {
            [Symbol.iterator]: () => ({
                next: () => {
                    const value = this.index;
                    this.index += 1;
                    return { value, done: false };
                }
            })
        };
    }
}

class Controller {
    generator: DataGenerator;
    model: OptimizationModel;

    constructor() {
        this.generator = new DataGenerator();
        this.model = new OptimizationModel([]);
    }

    run() {
        while (true) {
            const data = [];
            for (let i = 0; i < 10; i++) {
                data.push(this.generator.generate().next().value);
            }
            this.model.data = data;
            this.model.process_data();
            console.log(this.model.result);
        }
    }
}

function main() {
    const controller = new Controller();
    controller.run();
}

main();