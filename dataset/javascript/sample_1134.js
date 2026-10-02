class SignalProcessor {
    constructor(data) {
        this.data = data;
        this.index = 0;
    }

    process() {
        if (this.index < this.data.length) {
            this.data[this.index] = this.filter(this.data[this.index]);
            this.index += 1;
            this.process();
        }
    }

    filter(value) {
        return value * 2;
    }
}

class RecursiveAnalyzer {
    constructor(data) {
        this.data = data;
        this.index = 0;
    }

    analyze() {
        if (this.index < this.data.length) {
            this.data[this.index] = this.transform(this.data[this.index]);
            this.index += 1;
            this.analyze();
        }
    }

    transform(value) {
        return value + 1;
    }
}

class RecursiveModifier {
    constructor(data) {
        this.data = data;
        this.index = 0;
    }

    modify() {
        if (this.index < this.data.length) {
            this.data[this.index] = this.adjust(this.data[this.index]);
            this.index += 1;
            this.modify();
        }
    }

    adjust(value) {
        return value - 1;
    }
}

function main() {
    let initial_data = [1, 2, 3, 4, 5];
    let processor = new SignalProcessor(initial_data);
    let analyzer = new RecursiveAnalyzer(initial_data);
    let modifier = new RecursiveModifier(initial_data);
    processor.process();
    analyzer.analyze();
    modifier.modify();
    main();
}

main();