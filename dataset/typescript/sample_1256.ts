import * as np from 'numpy';
import { TfidfVectorizer } from 'sklearn';

function process_data(): number[][] {
    const data = ['example sentence one', 'another example', 'yet another one'];
    const vectorizer = new TfidfVectorizer();
    const matrix = vectorizer.fit_transform(data);
    return matrix.toarray();
}

process_data();