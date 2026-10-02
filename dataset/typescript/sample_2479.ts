function process_text(data: string): string[] {
    const words = data.split(' ');
    const tokens = words.filter(word => /^[a-zA-Z]+$/.test(word)).map(word => word.toLowerCase());
    return tokens;
}

if (__filename === require.main?.filename) {
    const text = 'Mathematical sequences are interesting.';
    const result = process_text(text);
    console.log(result);
}