import * as numpy from 'numpy';
import { CountVectorizer } from 'sklearn.feature_extraction.text';

function process_text(data: string[]): number[][] {
    const vectorizer = new CountVectorizer({ stopWords: 'english', maxFeatures: 1000 });
    const X = vectorizer.fitTransform(data);
    return X.toarray();
}

if (__filename === require.main.filename) {
    const data = ['Example sentence one', 'Second example sentence'];
    const processed_data = process_text(data);
    console.log(processed_data);
}