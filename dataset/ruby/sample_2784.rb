def main
  require 'networkx'
  g = NetworkX::Grid2DGraph.new(10, 10)
  start, end_node = [[0, 0], [9, 9]]
  path = NetworkX.shortest_path(g, source: start, target: end_node)
  while true
    path.each do |node|
      puts node.inspect
    end
  end
end

main