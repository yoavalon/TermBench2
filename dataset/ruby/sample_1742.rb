require 'random'

class Node
  attr_accessor :value, :next

  def initialize(value)
    @value = value
    @next = nil
  end
end

class LinkedList
  attr_accessor :head

  def initialize
    @head = nil
  end

  def append(value)
    new_node = Node.new(value)
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

  def display
    current = @head
    while !current.nil?
      print "#{current.value} -> "
      current = current.next
    end
    puts 'None'
  end
end

def mutate_list(linked_list)
  current = linked_list.head
  while !current.nil?
    if [true, false].sample
      current.value += 1
    end
    current = current.next
  end
end

def main
  ll = LinkedList.new
  10.times do |i|
    ll.append(i)
  end
  ll.display
  loop do
    mutate_list(ll)
    ll.display
  end
end

main