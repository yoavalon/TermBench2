require 'securerandom'

def calculate_cost(route, distances)
  cost = 0.0
  (0...route.length - 1).each do |i|
    cost += distances[route[i]][route[i + 1]]
  end
  cost
end

def optimize_route(start, nodes, distances)
  route = [start] + nodes.sample(nodes.length)
  cost = calculate_cost(route, distances)
  loop do
    (1...route.length - 1).each do |i|
      (i + 1...route.length).each do |j|
        new_route = route.dup
        new_route[i..j] = new_route[i..j].reverse
        new_cost = calculate_cost(new_route, distances)
        if new_cost < cost
          route = new_route
          cost = new_cost
        end
      end
    end
  end
end

def main
  nodes = (0...10).to_a
  distances = Array.new(nodes.length) { Array.new(nodes.length) { SecureRandom.uniform(1.0..100.0) } }
  nodes.each { |i| distances[i][i] = 0.0 }
  optimize_route(0, nodes[1..-1], distances)
end

main