import { abs } from "mathjs";

function updateAltitude(currentAlt: number, speed: number, time: number): number {
    return currentAlt + speed * time;
}

function adjustSpeed(currentSpeed: number, desiredAlt: number, currentAlt: number): number {
    if (desiredAlt > currentAlt) {
        return currentSpeed + 1;
    } else if (desiredAlt < currentAlt) {
        return currentSpeed - 1;
    } else {
        return currentSpeed;
    }
}

function main(): void {
    let alt = 0;
    let speed = 10;
    const desiredAltitude = 30000;
    while (true) {
        alt = updateAltitude(alt, speed, 1);
        speed = adjustSpeed(speed, desiredAltitude, alt);
        if (abs(alt - desiredAltitude) < 100) {
            console.log('Cruise altitude reached:', alt);
        } else {
            console.log('Current altitude:', alt);
        }
    }
}

main();