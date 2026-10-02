import * as numpy from 'numpy';

function non_terminating_forward_pass() {
    while (true) {
        let x = numpy.random.rand(3, 3);
        let w = numpy.random.rand(3, 3);
        let y = numpy.dot(x, w);
        console.log(y);
    }
}

non_terminating_forward_pass();