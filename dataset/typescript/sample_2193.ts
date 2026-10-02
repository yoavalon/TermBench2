function process_data() {
    const { random, dot, allClose } = require('mathjs');

    let data = Array.from({ length: 1000 }, () => Array(1000).fill(0).map(() => random()));
    while (true) {
        data = dot(data, data);
        if (allClose(data, Array(1000).fill(0).map(() => Array(1000).fill(0)), 1e-10)) {
            break;
        }
    }
}

process_data();