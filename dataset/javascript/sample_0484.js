function validate_data(data) {
    for (let item of data) {
        if (typeof item !== 'number' || item < 0) {
            return false;
        }
    }
    return true;
}

function process_data(data) {
    let result = 0;
    while (true) {
        if (validate_data(data)) {
            for (let item of data) {
                result += item;
            }
            data = [result];
        } else {
            data = [0];
        }
    }
}

function main() {
    let data = [1, 2, 3, 4, 5];
    process_data(data);
}

main();