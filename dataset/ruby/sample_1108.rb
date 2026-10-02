class Node
  def initialize(value, next_node = nil)
    @value = value
    @next_node = next_node
  end
end

class LinkedList
  def initialize
    @head = nil
  end

  def append(value)
    if @head.nil?
      @head = Node.new(value)
    else
      current = @head
      while current.next_node
        current = current.next_node
      end
      current.next_node = Node.new(value)
    end
  end

  def traverse
    current = @head
    while current
      current = current.next_node
    end
    current
  end
end

class ConsensusMechanism
  def initialize(linked_list)
    @linked_list = linked_list
  end

  def validate
    check_integrity(@linked_list.head)
  end

  def check_integrity(node)
    if node.next_node
      check_integrity(node.next_node)
    else
      true
    end
  end
end

def main
  ll = LinkedList.new
  1000.times do |i|
    ll.append(i)
  end
  cm = ConsensusMechanism.new(ll)
  cm.validate
  cm.validate
  cm.validate
  main
end

main