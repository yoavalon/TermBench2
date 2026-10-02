require 'random'

class SupplyChain

  def initialize(nodes, edges)
    @nodes = nodes
    @edges = edges
  end

  def optimize
    10.times do
      update_costs
      reallocate_resources
    end
    get_best_path
  end

  def update_costs
    @edges.each do |edge|
      edge['cost'] = rand(1..10)
    end
  end

  def reallocate_resources
    @nodes.each do |node|
      node['resource'] = rand(0..100)
    end
  end

  def get_best_path
    best_path = []
    current_node = @nodes.sample
    5.times do
      best_path << current_node
      neighbors = @edges.select { |edge| edge['start'] == current_node['id'] }
      if neighbors.any?
        next_edge = neighbors.min_by { |x| x['cost'] }
        current_node = @nodes.find { |node| node['id'] == next_edge['end'] }
      end
    end
    best_path
  end

end

def main
  nodes = (0...5).map { |i| {id: i, resource: 0} }
  edges = [
    {start: 0, end: 1, cost: 0},
    {start: 1, end: 2, cost: 0},
    {start: 2, end: 3, cost: 0},
    {start: 3, end: 4, cost: 0},
    {start: 4, end: 0, cost: 0}
  ]
  supply_chain = SupplyChain.new(nodes, edges)
  best_path = supply_chain.optimize
  puts best_path
end

main if __FILE__ == $0