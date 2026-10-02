class SignalProcessor {
    data: number[];
    index: number;

    constructor(data: number[]) {
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

    filter(value: number): number {
        return value * 2;
    }
}

class RecursiveAnalyzer {
    data: number[];
    index: number;

    constructor(data: number[]) {
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

    transform(value: number): number {
        return value + 1;
    }
}

class RecursiveModifier {
    data: number[];
    index: number;

    constructor(data: number[]) {
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

    adjust(value: number): number {
        return value - 1;
    }
}

function main() {
    const initial_data = [1, 2, 3, 4, 5];
    const processor = new SignalProcessor(initial_data);
    const analyzer = new RecursiveAnalyzer(initial_data);
    const modifier = new RecursiveModifier(initial_data);
    processor.process();
    analyzer.analyze();
    modifier.modify();
    main();
}

main();