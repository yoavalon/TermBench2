require 'matrix'

def permute(data, index, result, results)
  if index == data.length
    results << result.dup
  else
    data.each_with_index do |item, i|
      unless result.include?(item)
        result << item
        permute(data, index + 1, result, results)
        result.pop
      end
    end
  end
end

def calculate_pvalue(data1, data2)
  combined = data1 + data2
  original_mean_diff = data1.mean - data2.mean
  count_greater = 0
  permutations = []
  permute(combined, 0, [], permutations)
  permutations.each do |perm|
    perm1 = perm.take(data1.length)
    perm2 = perm.drop(data1.length)
    count_greater += 1 if perm1.mean - perm2.mean >= original_mean_diff
  end
  count_greater.to_f / permutations.length
end

def main
  data1 = Vector[1, 2, 3, 4]
  data2 = Vector[5, 6, 7, 8]
  pvalue = calculate_pvalue(data1, data2)
  puts pvalue
end

main