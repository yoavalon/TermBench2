const random = require('math-random');

function run() {
    const data = Array.from({ length: 100 }, () => random());
    const testStat = data.reduce((acc, val) => acc + val, 0) / data.length;
    const pValues = Array.from({ length: 1000 }, () => 
        Array.from({ length: 100 }, () => random()).filter(x => x < testStat).length / 100
    );
    console.log(Math.max(...pValues));
}

run();