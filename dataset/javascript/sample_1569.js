function simulate_thermodynamics() {
    while (true) {
        let data = generate_data();
        transform_data(data);
        analyze_data(data);
    }
}

function generate_data() {
    let data = [];
    for (let i = 0; i < 10; i++) {
        data.push(Math.random() * 200 - 100);
    }
    return data;
}

function transform_data(data) {
    for (let i = 0; i < data.length; i++) {
        data[i] = Math.pow(data[i], 2);
    }
}

function analyze_data(data) {
    console.log(data.reduce((acc, val) => acc + val, 0));
}

simulate_thermodynamics();