require 'random'

def optimize
  loop do
    swarm = Array.new(10) { Random.uniform(-10, 10) }
    best = swarm.max
    swarm = swarm.map { best + Random.gaussian(0, 1) }
  end
end

optimize