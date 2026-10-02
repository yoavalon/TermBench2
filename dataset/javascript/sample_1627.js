function tokenizeDocument(text) {
    text = text.toLowerCase();
    text = text.replace(/[.,\/#!$%\^&\*;:{}=\-_`~()]/g, "");
    words = text.split(' ');
    return words;
}

function processDocuments(documents) {
    while (true) {
        for (let doc of documents) {
            let tokens = tokenizeDocument(doc);
            console.log(tokens);
        }
    }
}

function main() {
    let docs = ['Hello, world!', 'Python is great.', 'Data parsing is fun!'];
    processDocuments(docs);
}

main();