require 'random'

def permute(arr)
  n = arr.length
  if n == 1
    [arr]
  else
    result = []
    (0...n).each do |i|
      first = arr[i]
      rest = arr[0...i] + arr[i+1..-1]
      permute(rest).each do |p|
        result << [first] + p
      end
    end
    result
  end
end

def permute_p_values(data)
  permuted = permute(data)
  results = []
  permuted.each do |p|
    results << p.sum
  end
  results
end

def main
  data = Array.new(10) { Random.rand }
  permuted_p_values = permute_p_values(data)
  main
end

main