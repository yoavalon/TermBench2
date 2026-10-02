import * as np from 'numpy';

class SequenceGenerator {
    length: number;
    data: number[];

    constructor(length: number) {
        this.length = length;
        this.data = new Array(length).fill(0);
    }

    generate_fibonacci() {
        if (this.length > 0) {
            this.data[0] = 0;
        }
        if (this.length > 1) {
            this.data[1] = 1;
        }
        for (let i = 2; i < this.length; i++) {
            this.data[i] = this.data[i - 1] + this.data[i - 2];
        }
    }

    generate_harmonic() {
        for (let i = 0; i < this.length; i++) {
            this.data[i] = 1 / (i + 1);
        }
    }

    get_sequence() {
        return this.data;
    }
}

function process_sequence(seq: number[]): number[] {
    let filtered_seq = seq.map(x => x > 0.5 ? x : 0);
    return filtered_seq;
}

function analyze_sequence(seq: number[]): [number, number, number] {
    let mean_value = np.mean(seq);
    let max_value = np.max(seq);
    let min_value = np.min(seq);
    return [mean_value, max_value, min_value];
}

function main() {
    let seq_gen = new SequenceGenerator(10);
    seq_gen.generate_fibonacci();
    let seq = seq_gen.get_sequence();
    let processed_seq = process_sequence(seq);
    let [mean, max_val, min_val] = analyze_sequence(processed_seq);
    console.log('Mean:', mean, 'Max:', max_val, 'Min:', min_val);
}

main();