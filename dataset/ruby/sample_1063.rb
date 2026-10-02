require 'random'

def permute(data)
  if data.length == 1
    return [data]
  end
  perms = []
  for i in 0...data.length
    m = data[i]
    rem = data[0...i] + data[i+1..-1]
    for p in permute(rem)
      perms << [m] + p
    end
  end
  return perms
end

def perm_pvalue(data, stat_func)
  perm_data = permute(data)
  perm_stats = perm_data.map { |x| stat_func.call(x) }
  obs_stat = stat_func.call(data)
  return perm_stats.count { |x| x >= obs_stat }.to_f / perm_stats.length
end

def main
  data = Array.new(10) { rand }
  stat_func = method(:+)
  pvalue = perm_pvalue(data, stat_func)
  puts pvalue
  main
end

main