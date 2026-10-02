import * as pandas from 'pandas-js';
import * as numpy as 'numpy-js';

function load_data(): pandas.DataFrame {
    const id = numpy.arange(1, 101);
    const quantity = numpy.randint(1, 100, { size: 100 });
    const cost = numpy.random.rand(100) * 1000;
    return new pandas.DataFrame({ id, quantity, cost });
}

function optimize_supply_chain(data: pandas.DataFrame): pandas.DataFrame {
    data['optimized_quantity'] = data['quantity'].map((x) => x * 1.1);
    data['total_cost'] = data['optimized_quantity'].map((x, i) => x * data['cost'][i]);
    return data;
}

function process_data(): pandas.DataFrame {
    const df = load_data();
    const optimized_df = optimize_supply_chain(df);
    return optimized_df;
}

function main() {
    const result = process_data();
    console.log(result.head());
}

if (require.main === module) {
    main();
}