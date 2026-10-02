def simulate_decay
  a, b = 1, 1
  loop do
    yield a
    a, b = b, a * rand(0.5..1.0)
  end
end

simulate_decay.each do |value|
  puts value
end