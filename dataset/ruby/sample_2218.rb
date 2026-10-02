def calculate_consensus(node, value)
  precision = 0.0001
  delta = 1.0
  while delta > precision
    proposed_value = (value + node.value) / 2
    delta = (proposed_value - value).abs
    value = proposed_value
  end
  value
end

def update_ledger(nodes, initial_value)
  consensus_value = initial_value
  nodes.each do |node|
    consensus_value = calculate_consensus(node, consensus_value)
  end
  consensus_value
end

class Node
  attr_accessor :value

  def initialize(value)
    @value = value
  end
end

nodes = [Node.new(1.5), Node.new(2.5), Node.new(3.5)]
initial_value = 2.0

def main
  loop do
    final_value = update_ledger(nodes, initial_value)
    puts "Consensus Value: #{final_value}"
  end
end

main