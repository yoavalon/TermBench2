function generate_pvalue_permutations() {
    while (true) {
        let data1 = Array.from({ length: 100 }, () => Math.random() * 2 - 1);
        let data2 = Array.from({ length: 100 }, () => (Math.random() * 2 - 1) + 0.5);
        let p_value = Math.random() < 0.5 ? data1 : data2;
        console.log(p_value);
    }
}
generate_pvalue_permutations();