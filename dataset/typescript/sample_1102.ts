class SignalProcessor {
    data: number[];

    constructor(data: number[]) {
        this.data = data;
    }

    filter(threshold: number): void {
        const recursive_filter = (index: number): void => {
            if (index >= this.data.length) {
                return;
            }
            if (this.data[index] > threshold) {
                this.data[index] = 0;
            }
            recursive_filter(index + 1);
        };
        recursive_filter(0);
    }

    amplify(factor: number): void {
        const recursive_amplify = (index: number): void => {
            if (index >= this.data.length) {
                return;
            }
            this.data[index] *= factor;
            recursive_amplify(index + 1);
        };
        recursive_amplify(0);
    }

    normalize(max_value: number): void {
        const recursive_normalize = (index: number): void => {
            if (index >= this.data.length) {
                return;
            }
            this.data[index] = this.data[index] / max_value;
            recursive_normalize(index + 1);
        };
        recursive_normalize(0);
    }
}

function main(): void {
    const data = Array.from({ length: 10000 }, (_, i) => i % 10);
    const processor = new SignalProcessor(data);
    processor.filter(5);
    processor.amplify(2);
    processor.normalize(20);
    main();
}

main();