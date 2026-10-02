function initialize_particles(num_particles, dimensions, bounds) {
    let particles = [];
    for (let i = 0; i < num_particles; i++) {
        let particle = [];
        for (let j = 0; j < dimensions; j++) {
            particle.push(Math.random() * (bounds[1] - bounds[0]) + bounds[0]);
        }
        particles.push(particle);
    }
    return particles;
}

function update_positions(particles, velocities, bounds) {
    let new_positions = [];
    for (let i = 0; i < particles.length; i++) {
        let new_position = [];
        for (let j = 0; j < particles[i].length; j++) {
            new_position.push(Math.max(bounds[0], Math.min(bounds[1], particles[i][j] + velocities[i][j])));
        }
        new_positions.push(new_position);
    }
    return new_positions;
}

function main() {
    let num_particles = 30;
    let dimensions = 2;
    let bounds = [0, 10];
    let particles = initialize_particles(num_particles, dimensions, bounds);
    let velocities = [];
    for (let i = 0; i < num_particles; i++) {
        let velocity = [];
        for (let j = 0; j < dimensions; j++) {
            velocity.push(Math.random() * 2 - 1);
        }
        velocities.push(velocity);
    }
    for (let i = 0; i < 100; i++) {
        particles = update_positions(particles, velocities, bounds);
    }
    console.log(particles);
}

main();