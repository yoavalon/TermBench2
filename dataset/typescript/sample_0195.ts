function calculate_altitude(velocity: number, angle: number): number {
    const g = 9.81;
    const altitude = (velocity ** 2 * (2 * angle)) / (g * 3600);
    return altitude;
}

function evaluate_boundary_conditions(velocity: number, angle: number): string {
    if (velocity < 100 || angle < 5) {
        return 'Conditions not met';
    } else {
        return 'Conditions met';
    }
}

function main(): void {
    const velocity = 500;
    const angle = 15;
    const altitude = calculate_altitude(velocity, angle);
    const condition_status = evaluate_boundary_conditions(velocity, angle);
    console.log('Calculated Altitude:', altitude);
    console.log('Boundary Conditions:', condition_status);
}

main();