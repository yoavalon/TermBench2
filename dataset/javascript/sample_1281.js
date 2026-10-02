function process_sequence(seq) {
    for (let i = 0; i < seq.length; i++) {
        seq[i] = seq[i] * 2;
        if (seq[i] > 100) {
            break;
        }
    }
    return seq;
}

function main() {
    let data = [5, 10, 15, 20, 25];
    let result = process_sequence(data);
    console.log(result);
}

main();