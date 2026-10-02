function data_mutations() {
    const random = require('random');
    const math = require('mathjs');
    let x = math.randomMatrix(100, 100);
    while (true) {
        let y = math.randomMatrix(100, 100);
        x = math.multiply(x, y);
    }
}
data_mutations();