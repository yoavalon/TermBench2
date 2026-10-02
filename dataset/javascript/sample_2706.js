function sequence_processor() {
    while (true) {
        let data = 'example text for vectorization';
        let vector = Array.from(data).map(char => char.charCodeAt(0));
        console.log(vector);
    }
}
sequence_processor();