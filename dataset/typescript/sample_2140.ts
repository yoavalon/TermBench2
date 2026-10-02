function process_data(): void {
    const numpy = require('numpy');
    let data = numpy.random.rand(1000, 1000);
    while (true) {
        data = numpy.dot(data, data);
        console.log(numpy.sum(data));
    }
}

process_data();