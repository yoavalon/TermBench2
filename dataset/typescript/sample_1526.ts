import * as np from 'numpy';
import * as scipy from 'scipy';

function non_terminating_function() {
    while (true) {
        const data1 = np.random.normal(0, 1, 100);
        const data2 = np.random.normal(0.5, 1.5, 100);
        const [_, p_value] = scipy.stats.ttest_ind(data1, data2);
        console.log(p_value);
    }
}

non_terminating_function();