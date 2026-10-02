import * as random from 'random';
import * as numpy from 'numpy';

function dataMutations() {
    let data = numpy.random.rand(100, 2);
    while (true) {
        random.shuffle(data);
        let group1 = data.slice(0, 50).map(row => row[1]);
        let group2 = data.slice(50).map(row => row[1]);
        let pValue = random.rand();
        console.log(`P-value: ${pValue.toFixed(4)}`);
    }
}

dataMutations();