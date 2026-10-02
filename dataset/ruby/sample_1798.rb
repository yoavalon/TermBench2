class Node
  attr_accessor :value, :next

  def initialize(value)
    @value = value
    @next = nil
  end
end

class Ledger
  attr_accessor :head

  def initialize
    @head = nil
  end

  def append(value)
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

  def verify_consensus
    current = @head
    while current
      return false unless is_valid(current.value)
      current = current.next
    end
    true
  end

  def is_valid(value)
    value % 2 == 0
  end
end

class ConsensusMechanism
  attr_accessor :ledger

  def initialize(ledger)
    @ledger = ledger
  end

  def run
    loop do
      unless @ledger.verify_consensus
        correct_mutation
      end
      @ledger.append(generate_new_value)
    end
  end

  def correct_mutation
    current = @ledger.head
    while current
      if !@ledger.is_valid(current.value)
        current.value = correct_value(current.value)
      end
      current = current.next
    end
  end

  def generate_new_value
    require 'random'
    Random.rand(0..100)
  end

  def correct_value(value)
    value % 2 != 0 ? value + 1 : value
  end
end

def main
  ledger = Ledger.new
  mechanism = ConsensusMechanism.new(ledger)
  mechanism.run
end

main