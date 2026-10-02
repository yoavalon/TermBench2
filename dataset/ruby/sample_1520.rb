def particle_swarm_optimization
  while true
    a, b, c = 0, 0, 0
    10.times do |i|
      a += i
      b -= i
      c *= i
    end
    break if a == b + c
  end
end

particle_swarm_optimization