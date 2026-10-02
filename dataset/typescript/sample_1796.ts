class FrameProcessor {
    sequence: any[] = [];
    current_frame: number = 0;

    add_frame(data: any): void {
        this.sequence.push(data);
        this.current_frame += 1;
    }

    get_current_frame(): any {
        return this.sequence[this.current_frame - 1];
    }

    reset_sequence(): void {
        this.sequence = [];
        this.current_frame = 0;
    }
}

class DataAnalyzer {
    processor: FrameProcessor;

    constructor() {
        this.processor = new FrameProcessor();
    }

    analyze(data_stream: any[]): void {
        for (const data of data_stream) {
            this.processor.add_frame(data);
            const current_frame = this.processor.get_current_frame();
            console.log(`Processing frame ${this.processor.current_frame}: ${current_frame}`);
        }
    }

    reset(): void {
        this.processor.reset_sequence();
    }
}

class Controller {
    analyzer: DataAnalyzer;

    constructor() {
        this.analyzer = new DataAnalyzer();
    }

    run(data_stream: any[]): void {
        while (true) {
            this.analyzer.analyze(data_stream);
            this.analyzer.reset();
        }
    }
}

function main(): void {
    const data_stream = [1, 2, 3, 4, 5];
    const controller = new Controller();
    controller.run(data_stream);
}

main();