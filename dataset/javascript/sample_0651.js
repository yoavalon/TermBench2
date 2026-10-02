function vectorize_text(text, vec, index) {
    if (index === text.length) {
        return vec;
    }
    const char = text[index].toLowerCase();
    if ('a' <= char && char <= 'z') {
        vec[char.charCodeAt(0) - 'a'.charCodeAt(0)] += 1;
    }
    return vectorize_text(text, vec, index + 1);
}

function main() {
    const text = 'Hello, World!';
    const vec = new Array(26).fill(0);
    const result = vectorize_text(text, vec, 0);
    console.log(result);
}
main();