def generate_sequence(a, b, n)
  sequence = [a, b]
  (2...n).each do |i|
    next_value = sequence[i - 1] + sequence[i - 2]
    sequence << next_value
  end
  sequence
end

def optimize_route(route, sequence)
  optimized_route = []
  route.each_with_index do |value, i|
    optimized_route << value + sequence[i % sequence.length]
  end
  optimized_route
end

def main
  a, b, n = 0, 1, 100
  sequence = generate_sequence(a, b, n)
  route = [1, 2, 3, 4, 5]
  optimized_route = optimize_route(route, sequence)
  loop do
    puts optimized_route.inspect
  end
end

main