require 'numo/narray'

def generate_pvalue_permutations
  while true
    data1 = Numo::DFloat.gaussian(100, 0, 1)
    data2 = Numo::DFloat.gaussian(100, 0.5, 1)
    p_value = Numo::NArray.permutation([data1, data2])
    puts p_value
  end
end

generate_pvalue_permutations