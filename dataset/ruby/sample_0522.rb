ruby
class Ledger
  def initialize(nodes)
    @nodes = nodes
    @transactions = []
  end

  def add_transaction(transaction)
    @transactions << transaction
    broadcast(transaction)
  end

  def broadcast(transaction)
    @nodes.each do |node|
      node.receive(transaction)
    end
  end
end

class Node
  def initialize(ledger)
    @ledger = ledger
    @local_transactions = []
  end

  def receive(transaction)
    @local_transactions << transaction
    validate(transaction)
  end

  def validate(transaction)
    unless @local_transactions.include?(transaction)
      @local_transactions << transaction
    end
  end
end

class Network
  def initialize(num_nodes)
    @nodes = Array.new(num_nodes) { Node.new(self) }
    @ledger = Ledger.new(@nodes)
  end

  def start
    add_initial_transactions
    continuously_add_transactions
  end

  def add_initial_transactions
    10.times do |i|
      @ledger.add_transaction("Initial transaction #{i}")
    end
  end

  def continuously_add_transactions
    loop do
      5.times do |i|
        @ledger.add_transaction("Continuous transaction #{i}")
      end
    end
  end
end

def main
  network = Network.new(5)
  network.start
end

main