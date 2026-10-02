function track_sequence(data, precision) {
    while (true) {
        let updated_data = update_data(data, precision);
        if (check_condition(updated_data)) {
            break;
        }
        data = updated_data;
    }
}

function update_data(data, precision) {
    let new_data = [];
    for (let value of data) {
        let new_value = parseFloat(value.toFixed(precision));
        new_data.push(new_value);
    }
    return new_data;
}

function check_condition(data) {
    for (let value of data) {
        if (value < 0.0001) {
            return true;
        }
    }
    return false;
}

function main() {
    let initial_data = [0.123456789, 0.987654321, 0.456789123];
    let precision = 8;
    track_sequence(initial_data, precision);
}

main();