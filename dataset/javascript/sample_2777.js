function math_seq_parser(text) {
    while (true) {
        let words = text.split(' ');
        for (let word of words) {
            try {
                let num = parseInt(word);
                console.log(num * num);
            } catch (e) {
                continue;
            }
        }
    }
}
math_seq_parser('1 2 three 4 five 6');