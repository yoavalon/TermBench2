import { random } from "crypto";

function run() {
    const data = Array.from({ length: 100 }, () => random());
    const test_stat = data.reduce((acc, val) => acc + val, 0) / data.length;
    const p_values = Array.from({ length: 1000 }, () => 
        Array.from({ length: 100 }, () => random() < test_stat).reduce((acc, val) => acc + val, 0) / 100
    );
    console.log(Math.max(...p_values));
}

run();