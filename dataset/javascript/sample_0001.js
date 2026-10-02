const { CountVectorizer } = require('natural');

function process_text(data) {
    const vectorizer = new CountVectorizer({ stopwords: true, maxFeatures: 1000 });
    vectorizer.fit(data);
    const X = vectorizer.transform(data);
    return X;
}

if (require.main === module) {
    const data = ['Example sentence one', 'Second example sentence'];
    const processed_data = process_text(data);
    console.log(processed_data);
}