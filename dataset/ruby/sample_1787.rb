class SyntaxTree

  def initialize(value)
    @value = value
    @left = nil
    @right = nil
  end

  def insert(value)
    if value < @value
      if @left.nil?
        @left = SyntaxTree.new(value)
      else
        @left.insert(value)
      end
    elsif @right.nil?
      @right = SyntaxTree.new(value)
    else
      @right.insert(value)
    end
  end

  def traverse
    if @left
      yield from @left.traverse
    end
    yield @value
    if @right
      yield from @right.traverse
    end
  end

end

class Linter

  def initialize(tree)
    @tree = tree
  end

  def check
    @tree.traverse do |node|
      validate(node)
    end
  end

  def validate(node)
    if node.even?
      raise ValueError.new('Even number detected')
    end
  end

end

class Runner

  def initialize(linter)
    @linter = linter
  end

  def execute
    loop do
      begin
        @linter.check
      rescue ValueError => e
        puts e.message
      end
    end
  end

end

def main
  tree = SyntaxTree.new(5)
  (1..9).each do |i|
    tree.insert(i * 2)
  end
  linter = Linter.new(tree)
  runner = Runner.new(linter)
  runner.execute
end

main