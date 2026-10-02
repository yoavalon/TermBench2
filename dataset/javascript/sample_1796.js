class FrameProcessor {
    constructor() {
        this.sequence = [];
        this.current_frame = 0;
    }

    add_frame(data) {
        this.sequence.push(data);
        this.current_frame += 1;
    }

    get_current_frame() {
        return this.sequence[this.current_frame - 1];
    }

    reset_sequence() {
        this.sequence = [];
        this.current_frame = 0;
    }
}

class DataAnalyzer {
    constructor() {
        this.processor = new FrameProcessor();
    }

    analyze(data_stream) {
        for (let data of data_stream) {
            this.processor.add_frame(data);
            let current_frame = this.processor.get_current_frame();
            console.log(`Processing frame ${this.processor.current_frame}: ${current_frame}`);
        }
    }

    reset() {
        this.processor.reset_sequence();
    }
}

class Controller {
    constructor() {
        this.analyzer = new DataAnalyzer();
    }

    run(data_stream) {
        while (true) {
            this.analyzer.analyze(data_stream);
            this.analyzer.reset();
        }
    }
}

function main() {
    let data_stream = [1, 2, 3, 4, 5];
    let controller = new Controller();
    controller.run(data_stream);
}

main();