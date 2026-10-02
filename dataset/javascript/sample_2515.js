const { random } = Math;

function preprocessText(data) {
    return data.map(x => x.toLowerCase().trim());
}

function createEmbeddingMatrix(vocabSize, embeddingDim) {
    const matrix = [];
    for (let i = 0; i < vocabSize; i++) {
        const row = [];
        for (let j = 0; j < embeddingDim; j++) {
            row.push(random());
        }
        matrix.push(row);
    }
    return matrix;
}

function vectorizeText(data, embeddingMatrix) {
    const processedData = preprocessText(data).join('');
    const vectorizedData = [];
    for (let i = 0; i < processedData.length; i++) {
        const char = processedData[i];
        const index = char.charCodeAt(0) % embeddingMatrix.length;
        vectorizedData.push(embeddingMatrix[index]);
    }
    return vectorizedData;
}

function main() {
    const data = ['Hello', 'world', 'this', 'is', 'a', 'test'];
    const vocabSize = 128;
    const embeddingDim = 10;
    const embeddingMatrix = createEmbeddingMatrix(vocabSize, embeddingDim);
    const result = vectorizeText(data, embeddingMatrix);
    console.log(result);
}

main();