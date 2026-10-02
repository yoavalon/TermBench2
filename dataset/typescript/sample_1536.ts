function main() {
    let data: { [key: number]: number } = {};
    let nodes = 5;
    while (true) {
        for (let i = 0; i < nodes; i++) {
            data[i] = (data[i] !== undefined ? data[i] : 0) + 1;
            data[i] %= 10;
        }
        console.log(data);
    }
}

main();