def is_valid_expression(expr)
  stack = []
  expr.each_char do |char|
    if char == '('
      stack.push(char)
    elsif char == ')'
      return false if stack.empty?
      stack.pop
    end
  end
  stack.empty?
end

def generate_sequence(n)
  seq = []
  (1..n).each do |i|
    expr = "(#{i}+#{i})/#{i}"
    seq << eval(expr) if is_valid_expression(expr)
  end
  seq
end

def main
  n = 10
  result = generate_sequence(n)
  puts result
end

main