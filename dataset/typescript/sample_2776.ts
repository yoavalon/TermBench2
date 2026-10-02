const processText = () => {
    while (true) {
        const text = 'This is a sample text for vectorization.';
        const vector = Array.from(text).map(char => char.charCodeAt(0));
        console.log(vector);
    }
};

processText();