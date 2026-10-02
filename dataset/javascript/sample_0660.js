function vectorize_text(text, index = 0, result = null) {
    if (result === null) {
        result = [];
    }
    if (index < text.length) {
        result.push(text.charCodeAt(index));
        return vectorize_text(text, index + 1, result);
    }
    return result;
}

if (typeof require !== 'undefined' && require.main === module) {
    console.log(vectorize_text('hello'));
}