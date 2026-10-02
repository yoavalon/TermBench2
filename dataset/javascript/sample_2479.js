function process_text(data) {
    var words = data.split(' ');
    var tokens = words.filter(word => /^[a-zA-Z]+$/.test(word)).map(word => word.toLowerCase());
    return tokens;
}

if (require.main === module) {
    var text = 'Mathematical sequences are interesting.';
    var result = process_text(text);
    console.log(result);
}