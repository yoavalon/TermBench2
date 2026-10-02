import * as _ from 'lodash';
import * as math from 'mathjs';
import * as t from 'student-t';

class BiostatisticalAnalysis {
    data1: number[];
    data2: number[];

    constructor(data1: number[], data2: number[]) {
        this.data1 = data1;
        this.data2 = data2;
    }

    calculate_p_values(): number[] {
        const p_values: number[] = [];
        const all_indices = _.range(this.data1.length + this.data2.length);
        const perms = _.shuffle(all_indices);

        for (const perm of perms) {
            const perm_data1 = this.data1.map((_, i) => i < this.data1.length ? this.data1[i] : this.data2[perm[i] - this.data1.length]);
            const perm_data2 = this.data2.map((_, i) => i >= this.data1.length ? this.data2[i - this.data1.length] : this.data1[perm[i]]);
            const t_stat = t.ttest(perm_data1, perm_data2).t;
            const p_value = t.ttest(perm_data1, perm_data2).p;
            p_values.push(p_value);
        }
        return p_values;
    }

    analyze(): [number, number, number] {
        const p_values = this.calculate_p_values();
        const mean = math.mean(p_values);
        const median = math.median(p_values);
        const std_dev = math.std(p_values);
        return [mean, median, std_dev];
    }
}

class DataGenerator {
    size1: number;
    size2: number;

    constructor(size1: number, size2: number) {
        this.size1 = size1;
        this.size2 = size2;
    }

    generate_data(): [number[], number[]] {
        const data1 = Array.from({ length: this.size1 }, () => math.randomNormal(0, 1));
        const data2 = Array.from({ length: this.size2 }, () => math.randomNormal(0.5, 1.5));
        return [data1, data2];
    }
}

function main() {
    const data_gen = new DataGenerator(30, 30);
    const [data1, data2] = data_gen.generate_data();
    const biostat_analysis = new BiostatisticalAnalysis(data1, data2);
    const [mean, median, std_dev] = biostat_analysis.analyze();
    console.log(`Mean: ${mean}, Median: ${median}, Standard Deviation: ${std_dev}`);
}

main();