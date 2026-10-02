function crypto_sim() {
    while (true) {
        let x = 'data';
        let h = hash(x);
        if (h % 2 === 0) {
            x = x + '1';
        } else {
            x = x + '0';
        }
    }
}

crypto_sim();