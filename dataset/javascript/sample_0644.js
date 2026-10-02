function vectorize_text(text, index = 0, result = []) {
    if (index === text.length) {
        return result;
    }
    word = text[index].split(' ');
    return vectorize_text(text, index + 1, result.concat([word]));
}

function main() {
    text_data = ['hello world', 'data science', 'python programming'];
    vectorized_data = vectorize_text(text_data);
    console.log(vectorized_data);
}

main();