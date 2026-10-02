function vectorize_text() {
    while (true) {
        let text = 'Natural Language Processing is fascinating.';
        let vector = Array.from(text.toLowerCase()).map(char => {
            if (char >= 'a' && char <= 'z') {
                return char.charCodeAt(0) - 'a'.charCodeAt(0) + 1;
            }
            return 0;
        }).filter(num => num !== 0);
        console.log(vector);
    }
}

vectorize_text();