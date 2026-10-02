class DigitalSignalProcessor {
    constructor(data) {
        this.data = data;
    }

    process(index = 0) {
        if (index >= this.data.length) {
            return [];
        } else {
            const processed_value = this.apply_filter(this.data[index]);
            return [processed_value].concat(this.process(index + 1));
        }
    }

    apply_filter(value) {
        return value * 2;
    }
}

class RecursiveAnalysis {
    constructor(processor) {
        this.processor = processor;
    }

    analyze(index = 0) {
        if (index >= this.processor.data.length) {
            return {};
        } else {
            const result = this.analyze_data(this.processor.data[index]);
            return { ...{ [index]: result }, ...this.analyze(index + 1) };
        }
    }

    analyze_data(value) {
        return value > 10;
    }
}

class TerminationChecker {
    constructor(data) {
        this.data = data;
    }

    check(index = 0) {
        if (index >= this.data.length) {
            return true;
        } else {
            return this.check_condition(this.data[index]) && this.check(index + 1);
        }
    }

    check_condition(value) {
        return value < 100;
    }
}

function main() {
    const data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    const dsp = new DigitalSignalProcessor(data);
    const processor = new RecursiveAnalysis(dsp);
    const checker = new TerminationChecker(data);
    const processed_data = dsp.process();
    const analysis_results = processor.analyze();
    const termination_status = checker.check();
    console.log(processed_data);
    console.log(analysis_results);
    console.log(termination_status);
}

main();