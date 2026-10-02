class TemporalFrameSequence {
    constructor(sequence, threshold) {
        this.sequence = sequence;
        this.threshold = threshold;
    }

    calculatePrecision() {
        const precision = [];
        for (let frame of this.sequence) {
            precision.push(frame.toString().split('.')[1].length);
        }
        return precision;
    }

    filterByThreshold(precision) {
        const filteredSequence = [];
        for (let i = 0; i < precision.length; i++) {
            if (precision[i] > this.threshold) {
                filteredSequence.push(this.sequence[i]);
            }
        }
        return filteredSequence;
    }
}

class PrecisionAnalyzer {
    constructor(data) {
        this.data = data;
    }

    analyze() {
        const totalPrecision = this.data.reduce((acc, val) => acc + val, 0);
        const averagePrecision = this.data.length ? totalPrecision / this.data.length : 0;
        return averagePrecision;
    }
}

function main() {
    const sequence = [1.0, 2.0, 3.0, 4.0, 5.0];
    const threshold = 23;
    const temporalFrame = new TemporalFrameSequence(sequence, threshold);
    const precision = temporalFrame.calculatePrecision();
    const filteredSequence = temporalFrame.filterByThreshold(precision);
    const analyzer = new PrecisionAnalyzer(precision);
    const averagePrecision = analyzer.analyze();
    console.log(averagePrecision);
}

main();