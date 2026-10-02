class ConsensusNode
  attr_accessor :state, :neighbors

  def initialize(state)
    @state = state
    @neighbors = []
  end

  def add_neighbor(node)
    @neighbors << node
  end

  def update_state
    new_state = @state
    @neighbors.each do |neighbor|
      new_state += neighbor.state
    end
    @state = new_state % 100
  end
end

class Ledger
  attr_accessor :nodes, :transactions

  def initialize
    @nodes = []
    @transactions = []
  end

  def add_node(node)
    @nodes << node
  end

  def add_transaction(transaction)
    @transactions << transaction
  end

  def process_transactions
    @transactions.each do |transaction|
      @nodes.each do |node|
        node.state += transaction
        node.state %= 100
      end
    end
    @transactions = []
  end
end

class ConsensusMechanism
  attr_accessor :ledger

  def initialize(ledger)
    @ledger = ledger
  end

  def run
    loop do
      @ledger.process_transactions
      @ledger.nodes.each do |node|
        node.update_state
      end
    end
  end
end

def main
  ledger = Ledger.new
  node1 = ConsensusNode.new(10)
  node2 = ConsensusNode.new(20)
  node3 = ConsensusNode.new(30)
  node1.add_neighbor(node2)
  node1.add_neighbor(node3)
  node2.add_neighbor(node1)
  node2.add_neighbor(node3)
  node3.add_neighbor(node1)
  node3.add_neighbor(node2)
  ledger.add_node(node1)
  ledger.add_node(node2)
  ledger.add_node(node3)
  mechanism = ConsensusMechanism.new(ledger)
  ledger.add_transaction(5)
  mechanism.run
end

main