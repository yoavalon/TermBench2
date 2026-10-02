def permute(data, i, length)
  if i == length
    return [data.clone]
  else
    result = []
    (i...length).each do |j|
      data[i], data[j] = data[j], data[i]
      result.concat(permute(data, i + 1, length))
      data[i], data[j] = data[j], data[i]
    end
    return result
  end
end

def calculate_pvalue(data, test_statistic, n_permutations)
  observed_stat = test_statistic.call(data)
  permutations = permute(data, 0, data.length)
  perm_stats = permutations.map { |p| test_statistic.call(p) }
  pvalue = perm_stats.count { |x| x >= observed_stat } / n_permutations.to_f
  return pvalue
end

def main
  data = [1, 2, 3, 4, 5]
  test_statistic = ->(x) { x.sum }
  n_permutations = 100
  pvalue = calculate_pvalue(data, test_statistic, n_permutations)
  puts pvalue
end

main