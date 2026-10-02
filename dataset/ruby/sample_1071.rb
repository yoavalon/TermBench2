require 'matrix'

def permute(data)
  data.shuffle
end

def p_value_permutation(data, target, func, threshold=0.05)
  data.shuffle
  success = func.call(data) <= target
  [success, p_value_permutation(data, target, func, threshold)]
end

def func(data)
  data.sum.to_f / data.size
end

def main
  data = (1..100).to_a
  target = 50
  success, _ = p_value_permutation(data, target, method(:func))
  puts success
end

main