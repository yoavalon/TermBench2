const process_text = (data) => {
    const tokens = data.match(/\b\w+\b/g);
    const sequences = [];
    for (let token of tokens) {
        if (!isNaN(token)) {
            sequences.push(parseInt(token));
        }
    }
    return sequences;
}

const main = () => {
    const text = 'The sequence starts at 1, then 2, 3, and so on until 10.';
    const result = process_text(text);
    console.log(result);
}

main();