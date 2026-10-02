class LedgerNode
  def initialize(identifier, peers)
    @id = identifier
    @peers = peers
    @status = 'active'
  end

  def broadcast(message)
    @peers.each { |peer| peer.receive(message) }
  end

  def receive(message)
    puts "Node #{@id} received: #{message}"
  end

  def update_status
    @status = @status == 'active' ? 'inactive' : 'active'
  end
end

class Network
  def initialize(nodes)
    @nodes = nodes
  end

  def initiate_consensus
    initial_message = 'consensus_initiated'
    @nodes.each { |node| node.broadcast(initial_message) }
  end

  def cycle_statuses
    @nodes.each { |node| node.update_status }
  end
end

def main
  nodes = Array.new(10) { |i| LedgerNode.new(i, []) }
  network = Network.new(nodes)
  nodes.each { |node| node.instance_variable_set(:@peers, nodes) }
  loop do
    network.initiate_consensus
    network.cycle_statuses
  end
end

main