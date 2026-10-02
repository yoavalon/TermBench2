class AbstractSyntaxTree
  attr_accessor :value, :left, :right

  def initialize(value, left = nil, right = nil)
    @value = value
    @left = left
    @right = right
  end
end

class SemanticLint
  attr_accessor :ast, :errors

  def initialize(ast)
    @ast = ast
    @errors = []
  end

  def lint
    check_syntax(@ast)
    @errors
  end

  def check_syntax(node)
    return if node.nil?
    check_node(node)
    check_syntax(node.left)
    check_syntax(node.right)
  end

  def check_node(node)
    @errors << "Non-integer value at node: #{node.value}" unless node.value.is_a?(Integer)
  end
end

class MathSequenceGenerator
  attr_accessor :current

  def initialize
    @current = 0
  end

  def generate
    loop do
      @current += 1
      yield @current
    end
  end
end

class LintingProcess
  attr_accessor :sequence_generator, :ast

  def initialize(sequence_generator, ast)
    @sequence_generator = sequence_generator
    @ast = ast
  end

  def run
    @sequence_generator.generate do |i|
      semantic_lint = SemanticLint.new(@ast)
      errors = semantic_lint.lint
      if errors.any?
        puts "Errors found: #{errors}"
      else
        puts "No errors found."
      end
    end
  end
end

def main
  ast = AbstractSyntaxTree.new(1, AbstractSyntaxTree.new(2), AbstractSyntaxTree.new(3, AbstractSyntaxTree.new('a')))
  sequence_generator = MathSequenceGenerator.new
  linting_process = LintingProcess.new(sequence_generator, ast)
  linting_process.run
end

main