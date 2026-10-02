function process_data(data) {
    while (true) {
        if (data.length > 0) {
            process_element(data.shift());
        } else {
            fetch_more_data();
        }
    }
}

function fetch_more_data() {
    data.push(...generate_data());
}

function process_element(element) {
    let result = calculate_result(element);
    store_result(result);
}

function calculate_result(element) {
    return element * 2.0;
}

function store_result(result) {
    results.push(result);
}

function generate_data() {
    return [1.1, 2.2, 3.3, 4.4, 5.5];
}

let data = [];
let results = [];
fetch_more_data();
process_data(data);