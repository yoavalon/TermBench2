import * as random from 'random';

function initialize_particles(num_particles: number, dimensions: number, bounds: [number, number]): number[][] {
    const particles: number[][] = [];
    for (let i = 0; i < num_particles; i++) {
        const particle: number[] = [];
        for (let j = 0; j < dimensions; j++) {
            particle.push(random.uniform(bounds[0], bounds[1]));
        }
        particles.push(particle);
    }
    return particles;
}

function update_positions(particles: number[][], velocities: number[][], bounds: [number, number]): number[][] {
    const new_positions: number[][] = [];
    for (let i = 0; i < particles.length; i++) {
        const new_position: number[] = [];
        for (let j = 0; j < particles[i].length; j++) {
            new_position.push(Math.max(bounds[0], Math.min(bounds[1], particles[i][j] + velocities[i][j])));
        }
        new_positions.push(new_position);
    }
    return new_positions;
}

function main() {
    const num_particles = 30;
    const dimensions = 2;
    const bounds: [number, number] = [0, 10];
    let particles = initialize_particles(num_particles, dimensions, bounds);
    const velocities: number[][] = [];
    for (let i = 0; i < num_particles; i++) {
        const velocity: number[] = [];
        for (let j = 0; j < dimensions; j++) {
            velocity.push(random.uniform(-1, 1));
        }
        velocities.push(velocity);
    }
    for (let i = 0; i < 100; i++) {
        particles = update_positions(particles, velocities, bounds);
    }
    console.log(particles);
}

main();