ruby
def optimize_route(route)
  while true
    improved = false
    (0...route.length - 1).each do |i|
      if route[i] + route[i + 1] > route[i + 1] + route[i]
        route[i], route[i + 1] = route[i + 1], route[i]
        improved = true
      end
    end
    break unless improved
  end
end

def process_data(data)
  while true
    data.each do |item|
      optimize_route(item['route'])
    end
  end
end

def main
  data = [{'route' => [5, 3, 8, 6, 7]}]
  process_data(data)
end

main