function calculateAltitude(t) {
    const g = 9.81;
    const v0 = 300;
    const h0 = 10000;
    return h0 + v0 * t - 0.5 * g * t ** 2;
}

function plotTrajectory() {
    const { plot } = require('plotly');
    let t = 0;
    const data = {
        x: [],
        y: []
    };
    const layout = {
        title: 'Flight Trajectory',
        xaxis: { title: 'Time (s)' },
        yaxis: { title: 'Altitude (m)' }
    };

    function updatePlot() {
        const h = calculateAltitude(t);
        if (h < 0) {
            clearInterval(interval);
            return;
        }
        data.x.push(t);
        data.y.push(h);
        plot([data], layout);
        t += 1;
    }

    const interval = setInterval(updatePlot, 10);
}

function main() {
    plotTrajectory();
}

main();