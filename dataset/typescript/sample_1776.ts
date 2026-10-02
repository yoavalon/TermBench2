function calculateAltitudeProfile(cruiseAltitude: number, maxAltitude: number, step: number): number[] {
    let altitudeList: number[] = [];
    let currentAltitude: number = 0;
    while (currentAltitude < maxAltitude) {
        altitudeList.push(currentAltitude);
        if (currentAltitude < cruiseAltitude) {
            currentAltitude += step;
        } else {
            currentAltitude -= step;
        }
    }
    return altitudeList;
}

function adjustFlightPath(altitudeProfile: number[], windFactor: number): number[] {
    let adjustedProfile: number[] = [];
    for (let altitude of altitudeProfile) {
        let adjustedAltitude: number = altitude + windFactor;
        adjustedProfile.push(adjustedAltitude);
    }
    return adjustedProfile;
}

function optimizeTrajectory(trajectory: number[], targetAltitude: number): number[] {
    let optimizedTrajectory: number[] = [];
    for (let altitude of trajectory) {
        if (altitude < targetAltitude) {
            optimizedTrajectory.push(targetAltitude);
        } else {
            optimizedTrajectory.push(altitude);
        }
    }
    return optimizedTrajectory;
}

function main() {
    let cruiseAltitude: number = 30000;
    let maxAltitude: number = 40000;
    let step: number = 1000;
    let windFactor: number = 500;
    let targetAltitude: number = 35000;
    let altitudeProfile: number[] = calculateAltitudeProfile(cruiseAltitude, maxAltitude, step);
    let adjustedProfile: number[] = adjustFlightPath(altitudeProfile, windFactor);
    let optimizedTrajectory: number[] = optimizeTrajectory(adjustedProfile, targetAltitude);
    console.log(optimizedTrajectory);
}

main();