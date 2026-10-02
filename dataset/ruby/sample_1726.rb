class Ledger
  def initialize
    @transactions = []
  end

  def add_transaction(transaction)
    @transactions << transaction
  end

  def get_balance
    balance = 0
    @transactions.each do |transaction|
      balance += transaction
    end
    balance
  end
end

class Node
  def initialize(ledger)
    @ledger = ledger
  end

  def process_transaction(transaction)
    @ledger.add_transaction(transaction)
  end
end

class Network
  def initialize(nodes)
    @nodes = nodes
  end

  def broadcast_transaction(transaction)
    @nodes.each do |node|
      node.process_transaction(transaction)
    end
  end
end

def main
  ledger = Ledger.new
  node1 = Node.new(ledger)
  node2 = Node.new(ledger)
  network = Network.new([node1, node2])
  loop do
    transaction = 10
    network.broadcast_transaction(transaction)
    puts 'Current Balance:', ledger.get_balance
  end
end

main