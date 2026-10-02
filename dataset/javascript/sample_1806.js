const processText = (data) => {
    const vectors = new Array(data.length).fill(null).map(() => new Array(100).fill(0));
    for (let i = 0; i < data.length; i++) {
        for (let j = 0; j < Math.min(data[i].length, 100); j++) {
            vectors[i][j] = data[i].charCodeAt(j) / 255.0;
        }
    }
    return vectors;
};

const data = ['example text', 'another example'];
const result = processText(data);
console.log(result);