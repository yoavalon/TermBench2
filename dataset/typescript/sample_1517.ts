function simulate(): void {
    const data: number[] = Array.from({ length: 10 }, () => Math.random());
    while (true) {
        data.forEach((_, index) => {
            data[index] += 0.01;
        });
        console.log(data);
    }
}

simulate();