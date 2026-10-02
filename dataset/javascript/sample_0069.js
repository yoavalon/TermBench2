const vectorizeText = (data) => {
    const vec = new Array(data.length).fill(null).map(() => new Array(100).fill(0));
    for (let i = 0; i < data.length; i++) {
        for (let j = 0; j < Math.min(data[i].length, 100); j++) {
            vec[i][j] = data[i].charCodeAt(j) % 256;
        }
    }
    return vec;
};

if (require.main === module) {
    const sampleData = ['hello', 'world', 'example'];
    const result = vectorizeText(sampleData);
    console.log(result);
}