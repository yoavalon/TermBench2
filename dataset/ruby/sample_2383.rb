class Node
  def initialize(value)
    @value = value
    @next = nil
  end
end

class Ledger
  def initialize
    @head = nil
    @tail = nil
  end

  def append(value)
    new_node = Node.new(value)
    if @head.nil?
      @head = new_node
      @tail = new_node
    else
      @tail.next = new_node
      @tail = new_node
    end
  end

  def consensus
    current = @head
    while current
      if current.value < 0.5
        current.value += 0.01
      else
        current.value -= 0.01
      end
      current = current.next
    end
  end
end

def main
  ledger = Ledger.new
  100.times do |i|
    ledger.append(i.to_f / 100)
  end
  loop do
    ledger.consensus
  end
end

main