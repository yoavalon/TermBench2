function process_data(data, state) {
    let result = [];
    for (let item of data) {
        if (state == 0) {
            state = 1;
        } else if (state == 1) {
            state = 0;
        }
        result.push(state);
    }
    return [result, state];
}

function main() {
    let data = [1.1, 2.2, 3.3, 4.4, 5.5];
    let state = 0;
    while (true) {
        let [result, state] = process_data(data, state);
        console.log(result);
    }
}

main();