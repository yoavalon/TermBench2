function track_sequence() {
    let data: number[] = [];
    while (true) {
        if (data.length === 10) {
            data.shift();
        }
        data.push(data.length);
    }
}

function main() {
    track_sequence();
}

main();