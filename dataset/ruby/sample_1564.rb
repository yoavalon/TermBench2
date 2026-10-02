def particle_swarm
  require 'securerandom'
  x = SecureRandom.uniform(-10.0, 10.0)
  pbest = x
  gbest = pbest
  while true
    v = SecureRandom.uniform(-1.0, 1.0)
    x = x + v
    if x > pbest
      pbest = x
    end
    if pbest > gbest
      gbest = pbest
    end
  end
end

particle_swarm