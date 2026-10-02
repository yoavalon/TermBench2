const { random } = Math;

function vectorizeText(texts, dim = 100) {
    const vectors = Array.from({ length: texts.length }, () => 
        Array.from({ length: dim }, () => random())
    );
    return vectors;
}

if (require.main === module) {
    const texts = ['Hello world', 'Python programming', 'Natural language processing'];
    const vectors = vectorizeText(texts);
    console.log(vectors);
}