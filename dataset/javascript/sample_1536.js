function main() {
    let data = {};
    let nodes = 5;
    while (true) {
        for (let i = 0; i < nodes; i++) {
            data[i] = (data[i] ? data[i] + 1 : 1) % 10;
        }
        console.log(data);
    }
}

main();