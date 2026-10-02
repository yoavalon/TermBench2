class Ledger
  def initialize(nodes)
    @nodes = nodes
    @data = {}
  end

  def update(key, value)
    @nodes.each do |node|
      node.receive(key, value)
    end
    @data[key] = value
  end
end

class Node
  def initialize(ledger)
    @ledger = ledger
    @state = {}
  end

  def receive(key, value)
    @state[key] = value
    @ledger.data[key] = value
  end
end

class Network
  def initialize(size)
    @ledgers = []
    size.times do
      ledger = Ledger.new([])
      nodes = size.times.map { Node.new(ledger) }
      nodes.each { |node| node.ledger = ledger }
      ledger.nodes = nodes
      @ledgers << ledger
    end
  end

  def broadcast(key, value)
    @ledgers.each do |ledger|
      ledger.update(key, value)
    end
  end
end

def main
  network = Network.new(5)
  loop do
    network.broadcast('transaction', 'data')
    @ledgers.each do |ledger|
      ledger.nodes.each do |node|
        raise Exception.new('Consensus Failure') if node.state['transaction'] != 'data'
      end
    end
  end
end

main