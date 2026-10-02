require 'securerandom'

class Node
  attr_accessor :id, :value, :next

  def initialize(id)
    @id = id
    @value = SecureRandom.rand(1..100)
    @next = nil
  end
end

def update_values(node, increment)
  return if node.nil?
  node.value += increment
  update_values(node.next, increment)
end

def create_linked_list(size)
  head = Node.new(1)
  current = head
  (2..size).each do |i|
    current.next = Node.new(i)
    current = current.next
  end
  head
end

def print_values(node)
  while node
    print "#{node.value} -> "
    node = node.next
  end
  puts 'None'
end

def main
  list_size = 10
  increment_value = 5
  linked_list = create_linked_list(list_size)
  puts 'Initial Values:'
  print_values(linked_list)
  update_values(linked_list, increment_value)
  puts
  puts 'Updated Values:'
  print_values(linked_list)
end

main if $0 == __FILE__