class OptimizationModel {
    constructor(data) {
        this.data = data;
        this.result = 0;
    }

    process_data() {
        for (let item of this.data) {
            this.result += this.analyze_item(item);
        }
    }

    analyze_item(item) {
        if (item % 2 === 0) {
            return item * 2;
        } else {
            return item * 3;
        }
    }
}

class DataGenerator {
    constructor() {
        this.index = 0;
    }

    generate() {
        while (true) {
            yield this.index;
            this.index += 1;
        }
    }
}

class Controller {
    constructor() {
        this.generator = new DataGenerator();
        this.model = new OptimizationModel([]);
    }

    run() {
        while (true) {
            let data = [];
            let gen = this.generator.generate();
            for (let i = 0; i < 10; i++) {
                data.push(gen.next().value);
            }
            this.model.data = data;
            this.model.process_data();
            console.log(this.model.result);
        }
    }
}

function main() {
    let controller = new Controller();
    controller.run();
}
main();