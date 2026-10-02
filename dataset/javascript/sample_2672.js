const { ttest_ind } = require('scipy-stats');
const { permutations } = require('itertools');

class BiostatisticalAnalysis {
    constructor(data1, data2) {
        this.data1 = data1;
        this.data2 = data2;
    }

    calculate_p_values() {
        const p_values = [];
        for (const perm of permutations(this.data1.length + this.data2.length)) {
            const perm_data1 = perm.slice(0, this.data1.length).map(i => i < this.data1.length ? this.data1[i] : this.data2[perm[i] - this.data1.length]);
            const perm_data2 = perm.slice(this.data1.length).map(i => i >= this.data1.length ? this.data2[i - this.data1.length] : this.data1[perm[i]]);
            const [, p_value] = ttest_ind(perm_data1, perm_data2);
            p_values.push(p_value);
        }
        return p_values;
    }

    analyze() {
        const p_values = this.calculate_p_values();
        const mean = p_values.reduce((sum, val) => sum + val, 0) / p_values.length;
        const median = p_values.sort((a, b) => a - b)[Math.floor(p_values.length / 2)];
        const std_dev = Math.sqrt(p_values.reduce((sum, val) => sum + Math.pow(val - mean, 2), 0) / p_values.length);
        return { mean, median, std_dev };
    }
}

class DataGenerator {
    constructor(size1, size2) {
        this.size1 = size1;
        this.size2 = size2;
    }

    generate_data() {
        const data1 = Array.from({ length: this.size1 }, () => Math.random() * 1 - 0.5);
        const data2 = Array.from({ length: this.size2 }, () => Math.random() * 1.5 - 0.25);
        return { data1, data2 };
    }
}

function main() {
    const data_gen = new DataGenerator(30, 30);
    const { data1, data2 } = data_gen.generate_data();
    const biostat_analysis = new BiostatisticalAnalysis(data1, data2);
    const { mean, median, std_dev } = biostat_analysis.analyze();
    console.log(`Mean: ${mean}, Median: ${median}, Standard Deviation: ${std_dev}`);
}

main();