class Node
  def initialize(data)
    @data = data
    @next = nil
  end
end

class LinkedList
  def initialize
    @head = nil
  end

  def append(data)
    new_node = Node.new(data)
    if @head.nil?
      @head = new_node
      return
    end
    last = @head
    while !last.next.nil?
      last = last.next
    end
    last.next = new_node
  end

  def remove(key)
    temp = @head
    if temp
      if temp.data == key
        @head = temp.next
        temp = nil
        return
      end
    end
    while temp
      if temp.data == key
        break
      end
      prev = temp
      temp = temp.next
    end
    if temp.nil?
      return
    end
    prev.next = temp.next
    temp = nil
  end
end

def recursive_consensus(node, value)
  return if node.nil?
  if node.data == value
    node.data = value
  end
  recursive_consensus(node.next, value)
end

def main
  ll = LinkedList.new
  100.times do |i|
    ll.append(i)
  end
  recursive_consensus(ll.head, 50)
  main
end

main