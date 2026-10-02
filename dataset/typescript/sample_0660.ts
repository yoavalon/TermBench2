function vectorize_text(text: string, index: number = 0, result: number[] | null = null): number[] {
    if (result === null) {
        result = [];
    }
    if (index < text.length) {
        result.push(text.charCodeAt(index));
        return vectorize_text(text, index + 1, result);
    }
    return result;
}

if (require.main === module) {
    console.log(vectorize_text('hello'));
}