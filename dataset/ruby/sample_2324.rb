require 'random'

class Particle
  def initialize(dim, lb, ub)
    @position = Array.new(dim) { rand(lb..ub) }
    @velocity = Array.new(dim) { rand(-1.0..1.0) }
    @best_position = @position.dup
    @best_fitness = Float::INFINITY
  end

  def update_velocity(global_best, w, c1, c2)
    (0...@velocity.length).each do |i|
      r1, r2 = rand, rand
      cognitive = c1 * r1 * (@best_position[i] - @position[i])
      social = c2 * r2 * (global_best[i] - @position[i])
      @velocity[i] = w * @velocity[i] + cognitive + social
    end
  end

  def update_position(lb, ub)
    (0...@position.length).each do |i|
      @position[i] += @velocity[i]
      @position[i] = [lb, @position[i], ub].max
    end
  end
end

def fitness_function(x)
  x.map { |xi| xi ** 2 }.sum
end

def optimize(dim, lb, ub, num_particles, w, c1, c2, max_iter)
  particles = Array.new(num_particles) { Particle.new(dim, lb, ub) }
  global_best = Array.new(dim, Float::INFINITY)
  global_best_fitness = Float::INFINITY
  max_iter.times do
    particles.each do |particle|
      current_fitness = fitness_function(particle.position)
      if current_fitness < particle.best_fitness
        particle.best_fitness = current_fitness
        particle.best_position = particle.position.dup
      end
      if current_fitness < global_best_fitness
        global_best_fitness = current_fitness
        global_best = particle.position.dup
      end
    end
    particles.each do |particle|
      particle.update_velocity(global_best, w, c1, c2)
      particle.update_position(lb, ub)
    end
  end
  [global_best, global_best_fitness]
end

def main
  dim = 30
  lb, ub = -100, 100
  num_particles = 50
  w, c1, c2 = 0.7, 1.5, 1.5
  max_iter = 10000
  best_position, best_fitness = optimize(dim, lb, ub, num_particles, w, c1, c2, max_iter)
  puts "Best position: #{best_position}"
  puts "Best fitness: #{best_fitness}"
end

main