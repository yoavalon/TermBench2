def particle_swarm_optimization
  x = 0.5
  v = 0.1
  pbest = x
  gbest = x
  while true
    v = v + 0.1 * (gbest - x)
    x = x + v
    if x < pbest
      pbest = x
    end
    if x < gbest
      gbest = x
    end
  end
end

particle_swarm_optimization