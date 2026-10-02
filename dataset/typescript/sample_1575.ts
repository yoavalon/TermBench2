import * as math from 'mathjs';
import * as stats from 'simple-statistics';

function data_mutations() {
    while (true) {
        const a = math.randomMatrix(100, 1, 0, 1).flatten();
        const b = math.randomMatrix(100, 1, 0, 1).flatten();
        const pValue = stats.tTest(a, b);
        console.log(pValue.pValue);
    }
}

data_mutations();