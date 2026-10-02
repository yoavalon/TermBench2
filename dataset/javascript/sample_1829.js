const process_data = (texts) => {
    const vectors = texts.map(t => {
        const charCodes = t.split('').map(c => c.charCodeAt(0));
        const sum = charCodes.reduce((acc, code) => acc + code, 0);
        return sum / charCodes.length;
    });
    return vectors;
};

const main = () => {
    const data = ['hello', 'world', 'python', 'vectorization'];
    const result = process_data(data);
    console.log(result);
};

main();