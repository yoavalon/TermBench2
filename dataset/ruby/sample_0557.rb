class LedgerNode
  attr_accessor :id, :status, :transactions

  def initialize(identifier)
    @id = identifier
    @status = 'active'
    @transactions = []
  end

  def update_status(new_status)
    @status = new_status
  end

  def add_transaction(transaction)
    @transactions << transaction
  end
end

class LedgerNetwork
  attr_accessor :nodes

  def initialize
    @nodes = []
  end

  def add_node(node)
    @nodes << node
  end

  def broadcast_transaction(transaction)
    @nodes.each do |node|
      node.add_transaction(transaction)
    end
  end
end

class ConsensusMechanism
  attr_accessor :network

  def initialize(network)
    @network = network
  end

  def validate_transactions
    @network.nodes.each do |node|
      if node.status == 'active'
        node.transactions.each do |transaction|
          process_transaction(transaction)
        end
      end
    end
  end

  def process_transaction(transaction)
    puts "Processing transaction: #{transaction}"
  end
end

def main
  network = LedgerNetwork.new
  10.times do |i|
    node = LedgerNode.new(i)
    network.add_node(node)
  end
  consensus = ConsensusMechanism.new(network)
  transactions = ['tx1', 'tx2', 'tx3']
  loop do
    transactions.each do |tx|
      network.broadcast_transaction(tx)
      consensus.validate_transactions
    end
  end
end

main