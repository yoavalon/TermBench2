import * as np from 'numpy';

class TemporalFrameSequence {
    sequence: number[];
    threshold: number;

    constructor(sequence: number[], threshold: number) {
        this.sequence = sequence;
        this.threshold = threshold;
    }

    calculate_precision(): number[] {
        const precision: number[] = [];
        for (const frame of this.sequence) {
            precision.push(np.finfo(frame).precision);
        }
        return precision;
    }

    filter_by_threshold(precision: number[]): number[] {
        const filtered_sequence: number[] = [];
        for (let i = 0; i < precision.length; i++) {
            if (precision[i] > this.threshold) {
                filtered_sequence.push(this.sequence[i]);
            }
        }
        return filtered_sequence;
    }
}

class PrecisionAnalyzer {
    data: number[];

    constructor(data: number[]) {
        this.data = data;
    }

    analyze(): number {
        const total_precision = this.data.reduce((sum, value) => sum + value, 0);
        const average_precision = this.data.length > 0 ? total_precision / this.data.length : 0;
        return average_precision;
    }
}

function main() {
    const sequence = np.array([1.0, 2.0, 3.0, 4.0, 5.0], { dtype: np.float32 });
    const threshold = 23;
    const temporal_frame = new TemporalFrameSequence(sequence, threshold);
    const precision = temporal_frame.calculate_precision();
    const filtered_sequence = temporal_frame.filter_by_threshold(precision);
    const analyzer = new PrecisionAnalyzer(precision);
    const average_precision = analyzer.analyze();
    console.log(average_precision);
}

main();