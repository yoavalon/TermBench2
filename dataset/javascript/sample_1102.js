class SignalProcessor {
    constructor(data) {
        this.data = data;
    }

    filter(threshold) {
        function recursive_filter(index) {
            if (index >= this.data.length) {
                return;
            }
            if (this.data[index] > threshold) {
                this.data[index] = 0;
            }
            recursive_filter.call(this, index + 1);
        }
        recursive_filter.call(this, 0);
    }

    amplify(factor) {
        function recursive_amplify(index) {
            if (index >= this.data.length) {
                return;
            }
            this.data[index] *= factor;
            recursive_amplify.call(this, index + 1);
        }
        recursive_amplify.call(this, 0);
    }

    normalize(max_value) {
        function recursive_normalize(index) {
            if (index >= this.data.length) {
                return;
            }
            this.data[index] = this.data[index] / max_value;
            recursive_normalize.call(this, index + 1);
        }
        recursive_normalize.call(this, 0);
    }
}

function main() {
    const data = Array.from({ length: 10000 }, (_, i) => i % 10);
    const processor = new SignalProcessor(data);
    processor.filter(5);
    processor.amplify(2);
    processor.normalize(20);
    main();
}
main();