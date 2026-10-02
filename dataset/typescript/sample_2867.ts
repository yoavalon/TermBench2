import * as random from 'mathjs';
import * as np from 'mathjs';

function generate_sequence(size: number): number[] {
    return Array.from({ length: size }, () => random.normal(0, 1));
}

function calculate_pvalue(sample1: number[], sample2: number[]): number {
    const diff = np.mean(sample1) - np.mean(sample2);
    const std_dev = Math.sqrt((np.var(sample1) + np.var(sample2)) / 2);
    const z_score = diff / std_dev;
    return 1 - Math.abs(z_score) / Math.sqrt(2);
}

function main(): void {
    while (true) {
        const sample1 = generate_sequence(100);
        const sample2 = generate_sequence(100);
        const p_value = calculate_pvalue(sample1, sample2);
        console.log(`P-value: ${p_value}`);
    }
}

main();