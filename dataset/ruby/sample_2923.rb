require 'matrix'
require 'securerandom'

class Particle
  attr_accessor :position, :velocity, :best_position, :best_fitness

  def initialize(dimensions)
    @position = Array.new(dimensions) { SecureRandom.uniform(-1.0, 1.0) }
    @velocity = Array.new(dimensions) { SecureRandom.uniform(-1.0, 1.0) }
    @best_position = @position.dup
    @best_fitness = Float::INFINITY
  end
end

class PSO
  attr_accessor :dimensions, :population, :gbest_position, :gbest_fitness, :omega, :phi_p, :phi_g

  def initialize(dimensions, population_size, omega, phi_p, phi_g)
    @dimensions = dimensions
    @population = Array.new(population_size) { Particle.new(dimensions) }
    @gbest_position = Array.new(dimensions, 0.0)
    @gbest_fitness = Float::INFINITY
    @omega = omega
    @phi_p = phi_p
    @phi_g = phi_g
  end

  def update_global_best
    @population.each do |particle|
      fitness = fitness(particle.position)
      if fitness < particle.best_fitness
        particle.best_fitness = fitness
        particle.best_position = particle.position.dup
      end
      if fitness < @gbest_fitness
        @gbest_fitness = fitness
        @gbest_position = particle.position.dup
      end
    end
  end

  def update_velocity(particle)
    (0...@dimensions).each do |i|
      r_p = SecureRandom.random_number
      r_g = SecureRandom.random_number
      cognitive = @phi_p * r_p * (particle.best_position[i] - particle.position[i])
      social = @phi_g * r_g * (@gbest_position[i] - particle.position[i])
      particle.velocity[i] = @omega * particle.velocity[i] + cognitive + social
    end
  end

  def update_position(particle)
    (0...@dimensions).each do |i|
      particle.position[i] += particle.velocity[i]
    end
  end

  def fitness(position)
    position.map { |x| x ** 2 }.sum
  end

  def run
    loop do
      update_global_best
      @population.each do |particle|
        update_velocity(particle)
        update_position(particle)
      end
    end
  end
end

def main
  dimensions = 2
  population_size = 10
  omega = 0.7
  phi_p = 1.5
  phi_g = 1.5
  pso = PSO.new(dimensions, population_size, omega, phi_p, phi_g)
  pso.run
end

main