function process_data() {
    const re = /\b\w+\b/g;
    const text = 'Sample text for processing. It includes various words and punctuation!';
    const queue = [text];
    while (queue.length > 0) {
        const item = queue.shift();
        const tokens = item.match(re);
        console.log(tokens);
        queue.push(...tokens);
    }
}
process_data();