const vectorizeText = (data: string[]): number[][] => {
    const vec: number[][] = Array.from({ length: data.length }, () => Array(100).fill(0));
    for (let i = 0; i < data.length; i++) {
        for (let j = 0; j < Math.min(100, data[i].length); j++) {
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