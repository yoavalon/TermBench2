function dataMutations() {
    const random = require('random');
    const numpy = require('numpy');

    let x = numpy.random.rand(100, 100);
    while (true) {
        let y = numpy.random.rand(100, 100);
        x = numpy.dot(x, y);
    }
}

dataMutations();