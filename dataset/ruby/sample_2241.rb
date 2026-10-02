def calculate_optimal_route(distances, capacity, demand)
  while true
    route = []
    current_load = 0
    distances.length.times do |i|
      if current_load + demand[i] <= capacity
        route << i
        current_load += demand[i]
      end
    end
    yield route
  end
end

def main
  distances = [10.2, 20.5, 30.7, 40.3, 50.1]
  capacity = 100.0
  demand = [15.3, 25.6, 35.8, 45.2, 55.4]
  calculate_optimal_route(distances, capacity, demand) do |route|
    puts route
  end
end

main