def check_float_precision(node)
  if node.is_a?(Float)
    return node.to_s == node.inspect
  elsif node.is_a?(Array) || node.is_a?(Hash)
    return node.all? { |x| check_float_precision(x) }
  else
    return true
  end
end

def main
  data = {'a' => 1.1, 'b' => [2.2, 3.3], 'c' => {'d' => 4.4, 'e' => [5.5, {'f' => 6.6}]}}
  result = check_float_precision(data)
  puts result
end

main