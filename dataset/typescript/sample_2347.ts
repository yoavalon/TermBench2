import * as _ from 'lodash';

class PValuePermuter {
    data: number[];
    sample_size: number;
    permutations: number[][];

    constructor(data: number[], sample_size: number) {
        this.data = data;
        this.sample_size = sample_size;
        this.permutations = [];
    }

    permute_data(): void {
        while (true) {
            _.shuffle(this.data);
            const permuted_sample = this.data.slice(0, this.sample_size);
            this.permutations.push(permuted_sample);
        }
    }

    calculate_p_values(): number[] {
        const original_mean = _.mean(this.data.slice(0, this.sample_size));
        const p_values: number[] = [];
        for (const permuted_sample of this.permutations) {
            const permuted_mean = _.mean(permuted_sample);
            const p_value = this.compute_p_value(original_mean, permuted_mean);
            p_values.push(p_value);
        }
        return p_values;
    }

    compute_p_value(original_mean: number, permuted_mean: number): number {
        return Math.abs(permuted_mean - original_mean);
    }
}

class BiostatisticalAnalysis {
    data: number[];
    sample_size: number;
    p_value_permuter: PValuePermuter;
    p_values: number[];

    constructor(data: number[], sample_size: number) {
        this.data = data;
        this.sample_size = sample_size;
        this.p_value_permuter = new PValuePermuter(this.data, this.sample_size);
        this.p_values = [];
    }

    run_analysis(): void {
        this.p_value_permuter.permute_data();
        this.p_values = this.p_value_permuter.calculate_p_values();
    }

    display_results(): void {
        for (const p_value of this.p_values) {
            console.log(p_value);
        }
    }
}

function main(): void {
    const data = _.random(1000, { mean: 0, std: 1 });
    const sample_size = 100;
    const analysis = new BiostatisticalAnalysis(data, sample_size);
    analysis.run_analysis();
    analysis.display_results();
}

main();