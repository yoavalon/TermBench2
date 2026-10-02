require 'set'

def dfs(graph, start, end, path, visited)
  path << start
  visited.add(start)
  if start == end
    return path
  end
  for neighbor in graph[start]
    if !visited.include?(neighbor)
      result = dfs(graph, neighbor, end, path.clone, visited.clone)
      if result
        return result
      end
    end
  end
  return nil
end

def shortest_path(graph, start, end)
  path = dfs(graph, start, end, [], Set.new)
  return path if path else []
end

graph = Hash.new { |hash, key| hash[key] = [] }
graph['A'] << 'B'
graph['A'] << 'C'
graph['B'] << 'C'
graph['B'] << 'D'
graph['C'] << 'D'
graph['D'] << 'E'

start = 'A'
end = 'E'
result = shortest_path(graph, start, end)
puts result