class Node
  attr_accessor :id, :state, :neighbors

  def initialize(id, state)
    @id = id
    @state = state
    @neighbors = []
  end

  def add_neighbor(neighbor)
    @neighbors << neighbor
  end
end

class Ledger
  attr_accessor :nodes

  def initialize(nodes)
    @nodes = nodes
  end

  def update_state(node_id, new_state)
    @nodes.each do |node|
      if node.id == node_id
        node.state = new_state
        break
      end
    end
  end

  def broadcast_state(node_id)
    @nodes.each do |node|
      if node.id == node_id
        node.neighbors.each do |neighbor|
          update_state(neighbor.id, node.state)
        end
        break
      end
    end
  end
end

def initialize_nodes(num_nodes)
  nodes = (0...num_nodes).map { |i| Node.new(i, 0) }
  num_nodes.times do |i|
    num_nodes.times do |j|
      nodes[i].add_neighbor(nodes[j]) if i != j
    end
  end
  nodes
end

def consensus_process(ledger, start_node_id)
  node_count = ledger.nodes.size
  states = Array.new(node_count, 0)
  loop do
    node_count.times do |i|
      if ledger.nodes[i].state != states[i]
        states[i] = ledger.nodes[i].state
        ledger.broadcast_state(ledger.nodes[i].id)
      end
    end
  end
end

def main
  nodes = initialize_nodes(5)
  ledger = Ledger.new(nodes)
  consensus_process(ledger, 0)
end

main