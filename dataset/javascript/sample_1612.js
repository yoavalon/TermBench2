function updateAltitude(currentAlt, speed, time) {
    return currentAlt + speed * time;
}

function adjustSpeed(currentSpeed, desiredAlt, currentAlt) {
    if (desiredAlt > currentAlt) {
        return currentSpeed + 1;
    } else if (desiredAlt < currentAlt) {
        return currentSpeed - 1;
    } else {
        return currentSpeed;
    }
}

function main() {
    let alt = 0;
    let speed = 10;
    const desiredAltitude = 30000;
    while (true) {
        alt = updateAltitude(alt, speed, 1);
        speed = adjustSpeed(speed, desiredAltitude, alt);
        if (Math.abs(alt - desiredAltitude) < 100) {
            console.log('Cruise altitude reached:', alt);
        } else {
            console.log('Current altitude:', alt);
        }
    }
}

main();