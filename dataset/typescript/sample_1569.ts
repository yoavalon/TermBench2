function simulate_thermodynamics() {
    while (true) {
        let data = generate_data();
        data = transform_data(data);
        analyze_data(data);
    }
}

function generate_data() {
    const random = require('random');
    return Array.from({ length: 10 }, () => random.uniform(-100, 100));
}

function transform_data(data) {
    return data.map(x => x ** 2);
}

function analyze_data(data) {
    console.log(data.reduce((acc, val) => acc + val, 0));
}

simulate_thermodynamics();