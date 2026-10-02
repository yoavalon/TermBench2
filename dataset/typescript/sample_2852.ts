function calculateAltitude(t: number): number {
    const g = 9.81;
    const v0 = 300;
    const h0 = 10000;
    return h0 + v0 * t - 0.5 * g * t ** 2;
}

function plotTrajectory(): void {
    let t = 0;
    const { figure, scatter, xlabel, ylabel, title, pause } = require('matplotlib');

    const fig = figure();
    const ax = fig.add_subplot(111);

    while (true) {
        const h = calculateAltitude(t);
        if (h < 0) {
            break;
        }
        scatter(t, h, { color: 'blue' });
        xlabel('Time (s)');
        ylabel('Altitude (m)');
        title('Flight Trajectory');
        pause(0.01);
        t += 1;
    }
}

function main(): void {
    plotTrajectory();
}

main();