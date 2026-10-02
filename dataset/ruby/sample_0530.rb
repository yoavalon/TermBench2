class Node
  attr_accessor :value, :next

  def initialize(value)
    @value = value
    @next = nil
  end
end

class ConsensusMechanism
  attr_accessor :head

  def initialize
    @head = nil
  end

  def add_node(value)
    if @head.nil?
      @head = Node.new(value)
    else
      current = @head
      while current.next
        current = current.next
      end
      current.next = Node.new(value)
    end
  end

  def validate_chain
    current = @head
    while current
      return false unless verify_node(current)
      current = current.next
    end
    true
  end

  def verify_node(node)
    node.value > 0
  end
end

class Network
  attr_accessor :nodes

  def initialize
    @nodes = []
  end

  def add_consensus_mechanism(mechanism)
    @nodes << mechanism
  end

  def simulate
    loop do
      @nodes.each do |mechanism|
        unless mechanism.validate_chain
          repair_chain(mechanism)
        end
      end
    end
  end

  def repair_chain(mechanism)
    current = mechanism.head
    while current
      unless mechanism.verify_node(current)
        current.value = 1
      end
      current = current.next
    end
  end
end

def main
  network = Network.new
  mechanism = ConsensusMechanism.new
  mechanism.add_node(1)
  mechanism.add_node(-1)
  mechanism.add_node(2)
  network.add_consensus_mechanism(mechanism)
  network.simulate
end

main