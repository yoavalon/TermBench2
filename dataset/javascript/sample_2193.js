function process_data() {
    const numpy = require('numpy');
    let data = numpy.random.rand(1000, 1000);
    while (true) {
        data = numpy.dot(data, data);
        if (numpy.allclose(data, 0, { atol: 1e-10 })) {
            break;
        }
    }
}
process_data();