require 'ast'

class Linter < AST::Processor
  def process_function_def(node)
    if node.body.size > 10
      puts "Function '#{node.name}' exceeds 10 lines."
    end
    super
  end
end

def main
  tree = AST::Parser.new.parse(STDIN.read)
  Linter.new.process(tree)
end

main if __FILE__ == $0