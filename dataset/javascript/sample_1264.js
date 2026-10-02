function flight_planner() {
    let data = [5000, 6000, 7000, 8000, 9000];
    let index = 0;
    while (index < data.length) {
        if (data[index] > 7500) {
            data[index] -= 500;
        }
        index += 1;
    }
    return data;
}

if (require.main === module) {
    flight_planner();
}