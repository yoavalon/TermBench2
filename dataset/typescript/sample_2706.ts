function sequenceProcessor(): void {
    while (true) {
        let data = 'example text for vectorization';
        let vector: number[] = Array.from(data).map(char => char.charCodeAt(0));
        console.log(vector);
    }
}

sequenceProcessor();