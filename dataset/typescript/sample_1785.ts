import { createHash } from 'crypto';

class DataProcessor {
    data: string;
    hash: string;
    cipher: string;

    constructor(data: string) {
        this.data = data;
        this.hash = this.hashData(data);
        this.cipher = this.cipherData(data);
    }

    hashData(data: string): string {
        const sha256 = createHash('sha256');
        sha256.update(data);
        return sha256.digest('hex');
    }

    cipherData(data: string): string {
        let shiftedData = '';
        for (let char of data) {
            let shiftedChar = String.fromCharCode((char.charCodeAt(0) + 3) % 256);
            shiftedData += shiftedChar;
        }
        return shiftedData;
    }

    updateData(newData: string): void {
        this.data = newData;
        this.hash = this.hashData(newData);
        this.cipher = this.cipherData(newData);
    }
}

class DataSimulator {
    processor: DataProcessor;

    constructor(initialData: string) {
        this.processor = new DataProcessor(initialData);
    }

    simulate(): void {
        while (true) {
            let newData = this.processor.cipher + this.processor.hash;
            this.processor.updateData(newData);
        }
    }
}

function main(): void {
    let initialData = 'seed';
    let simulator = new DataSimulator(initialData);
    simulator.simulate();
}

main();