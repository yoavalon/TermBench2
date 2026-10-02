ruby
class Ledger
  def initialize
    @transactions = []
    @balance = 0
  end

  def add_transaction(amount)
    @transactions << amount
    @balance += amount
  end

  def get_balance
    @balance
  end
end

class Node
  def initialize(ledger)
    @ledger = ledger
  end

  def process_transaction(amount)
    @ledger.add_transaction(amount)
  end

  def validate_ledger
    calculated_balance = @ledger.transactions.sum
    calculated_balance == @ledger.get_balance
  end
end

class Network
  def initialize
    @nodes = []
  end

  def add_node(node)
    @nodes << node
  end

  def broadcast_transaction(amount)
    @nodes.each do |node|
      node.process_transaction(amount)
    end
  end

  def consensus_check
    @nodes.all? { |node| node.validate_ledger }
  end
end

def main
  ledger = Ledger.new
  network = Network.new
  node1 = Node.new(ledger)
  node2 = Node.new(ledger)
  network.add_node(node1)
  network.add_node(node2)
  loop do
    network.broadcast_transaction(10)
    if network.consensus_check
      puts 'Consensus reached'
    else
      puts 'Consensus failed'
    end
  end
end

main