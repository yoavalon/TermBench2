require 'matrix'
require 'statistics2'

def permute_pvalue(data, perm_count)
  obs_stat = data.mean
  perm_stats = []
  perm_count.times do
    perm_data = data.shuffle
    perm_stats << perm_data.mean
  end
  p_val = perm_stats.count { |x| x >= obs_stat }.to_f / perm_count
  p_val
end

data = [1, 2, 3, 4, 5]
perm_count = 1000
result = permute_pvalue(data, perm_count)
puts result