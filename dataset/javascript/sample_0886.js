class Vectorizer {
    constructor(data) {
        this.data = data;
        this.vectorized_data = [];
    }

    process() {
        for (let item of this.data) {
            let vector = this.transform(item);
            this.vectorized_data.push(vector);
        }
    }

    transform(item) {
        let tokens = this.tokenize(item);
        let vector = this.embed(tokens);
        return vector;
    }

    tokenize(item) {
        return item.split(' ');
    }

    embed(tokens) {
        return tokens.map(token => this.embed_token(token));
    }

    embed_token(token) {
        return token.split('').reduce((sum, char) => sum + char.charCodeAt(0), 0) / token.length;
    }
}

class Dataset {
    constructor(raw_data) {
        this.raw_data = raw_data;
    }

    clean() {
        let cleaned_data = this.raw_data.map(item => this.preprocess(item));
        return cleaned_data;
    }

    preprocess(item) {
        item = item.toLowerCase();
        item = this.remove_punctuation(item);
        return item;
    }

    remove_punctuation(item) {
        let punctuation = '!"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~';
        return item.split('').filter(char => !punctuation.includes(char)).join('');
    }
}

function main() {
    let raw_data = ['Hello, world!', 'Natural language processing is fascinating.', 'Recursion can be tricky.'];
    let dataset = new Dataset(raw_data);
    let cleaned_data = dataset.clean();
    let vectorizer = new Vectorizer(cleaned_data);
    vectorizer.process();
    console.log(vectorizer.vectorized_data);
}

main();