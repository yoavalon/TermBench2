def optimize_route(routes, start, end, visited = nil, path = nil)
    visited ||= []
    path ||= []
    visited << start
    path << start
    return path if start == end
    routes.fetch(start, {}).each do |neighbor, distance|
        unless visited.include?(neighbor)
            result = optimize_route(routes, neighbor, end, visited.dup, path.dup)
            return result if result
        end
    end
    nil
end

def main
    routes = {'A' => {'B' => 10, 'C' => 15}, 'B' => {'C' => 35, 'D' => 25}, 'C' => {'D' => 30}, 'D' => {}}
    start = 'A'
    end = 'D'
    optimal_path = optimize_route(routes, start, end)
    puts optimal_path
end

main