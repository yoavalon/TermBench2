def generate_sequence(n)
  sequence = []
  (0...n).each do |i|
    sequence << (i * (i + 1)) / 2
  end
  sequence
end

def optimize_transport(routes, capacity)
  optimized_routes = []
  routes.each do |route|
    if route.sum <= capacity
      optimized_routes << route
    end
  end
  optimized_routes
end

def main
  n = 5
  capacity = 15
  routes = generate_sequence(n)
  optimized = optimize_transport([routes], capacity)
  puts optimized
end

main