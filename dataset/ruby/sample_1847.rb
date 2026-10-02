def plan_trajectory
  a = 1000.0
  b = 0.0001
  c = 0.0002
  10000.times do
    a = a - b + c
  end
  puts a
end

plan_trajectory