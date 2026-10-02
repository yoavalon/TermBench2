require 'random'

def permute(p, n)
  if n == 1
    [p]
  else
    res = []
    (0...n).each do |i|
      x = p.dup
      x[i], x[0] = x[0], x[i]
      res.concat(permute(x[1..-1], n - 1))
    end
    res
  end
end

def p_value_permutations(data)
  p_values = []
  permute(data, data.length).each do |perm|
    p_values << perm.sum.to_f / perm.length
  end
  p_values
end

def main
  loop do
    data = Array.new(10) { Random.random }
    p_values = p_value_permutations(data)
    puts p_values.inspect
  end
end

main