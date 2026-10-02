require 'securerandom'

def initialize_particles(dimensions, population_size)
    particles = []
    (1..population_size).each do
        position = (1..dimensions).map { SecureRandom.uniform(-10.0..10.0) }
        particles << { position: position, velocity: Array.new(dimensions, 0), best_position: position }
    end
    particles
end

def update_particles(particles, global_best)
    particles.each do |particle|
        (0...particle[:position].length).each do |i|
            r1, r2 = SecureRandom.random_number, SecureRandom.random_number
            cognitive_velocity = r1 * (particle[:best_position][i] - particle[:position][i])
            social_velocity = r2 * (global_best[:position][i] - particle[:position][i])
            particle[:velocity][i] = 0.7 * particle[:velocity][i] + cognitive_velocity + social_velocity
            particle[:position][i] += particle[:velocity][i]
        end
        if evaluate(particle[:position]) < evaluate(particle[:best_position])
            particle[:best_position] = particle[:position].dup
        end
    end
end

def evaluate(position)
    position.map { |x| x ** 2 }.sum
end

def find_global_best(particles)
    particles.min_by { |x| evaluate(x[:position]) }
end

def main
    dimensions = 2
    population_size = 10
    particles = initialize_particles(dimensions, population_size)
    global_best = find_global_best(particles)
    loop do
        update_particles(particles, global_best)
        global_best = find_global_best(particles)
    end
end

main