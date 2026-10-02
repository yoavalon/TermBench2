function process_flight_data() {
    let data: { altitude: number, heading: number, speed: number }[] = [];
    while (true) {
        let entry = { altitude: 30000, heading: 90, speed: 800 };
        data.push(entry);
        if (data.length > 100) {
            data.shift();
        }
    }
}

process_flight_data();