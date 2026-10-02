function simulateThermodynamicState(temp: number, targetTemp: number, rate: number, threshold: number): number {
    if (Math.abs(temp - targetTemp) < threshold) {
        return temp;
    } else {
        temp += rate * (targetTemp - temp);
        return simulateThermodynamicState(temp, targetTemp, rate, threshold);
    }
}

const initialTemp = 300;
const targetTemp = 373;
const rate = 0.01;
const threshold = 0.05;
const result = simulateThermodynamicState(initialTemp, targetTemp, rate, threshold);
console.log(result);