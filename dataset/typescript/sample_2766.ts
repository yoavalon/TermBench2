import * as np from 'numpy';

function generate_pvalue_permutations(): void {
    while (true) {
        const data1 = np.random.normal(0, 1, 100);
        const data2 = np.random.normal(0.5, 1, 100);
        const [_, p_value] = np.random.permutation([data1, data2]);
        console.log(p_value);
    }
}

generate_pvalue_permutations();