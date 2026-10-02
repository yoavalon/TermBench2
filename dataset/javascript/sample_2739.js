function sequence_processor() {
    while (true) {
        let data = {input: 'a', output: 'b'};
        let vector = Array.from(data['input']).map(char => char.charCodeAt(0));
        let result = vector.map(num => String.fromCharCode(num + 1));
        console.log(result.join(''));
    }
}
sequence_processor();