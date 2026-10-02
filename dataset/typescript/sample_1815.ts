import * as _ from 'lodash';

function vectorize_text(texts: string[], dim: number = 100): number[][] {
    const vectors = _.range(texts.length).map(() => _.fill(Array(dim), Math.random()));
    return vectors;
}

if (require.main === module) {
    const texts = ['Hello world', 'Python programming', 'Natural language processing'];
    const vectors = vectorize_text(texts);
    console.log(vectors);
}