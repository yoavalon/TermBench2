def match(a, b)
  if a == b
    1
  else
    -1
  end
end

def score(x, y, i, j)
  if i == 0 || j == 0
    0
  else
    [score(x, y, i - 1, j - 1) + match(x[i - 1], y[j - 1]), score(x, y, i, j - 1) - 1, score(x, y, i - 1, j) - 1].max
  end
end

def align(x, y, i, j)
  if i == 0 || j == 0
    return ['', '']
  end
  if x[i - 1] == y[j - 1]
    s1, s2 = align(x, y, i - 1, j - 1)
    return [x[i - 1] + s1, y[j - 1] + s2]
  else
    scores = [score(x, y, i - 1, j - 1), score(x, y, i, j - 1), score(x, y, i - 1, j)]
    idx = scores.index(scores.max)
    if idx == 0
      s1, s2 = align(x, y, i - 1, j - 1)
      return [x[i - 1] + s1, y[j - 1] + s2]
    elsif idx == 1
      s1, s2 = align(x, y, i, j - 1)
      return ['_' + s1, y[j - 1] + s2]
    else
      s1, s2 = align(x, y, i - 1, j)
      return [x[i - 1] + s1, '_' + s2]
    end
  end
end

def main
  x = 'AGGTAB'
  y = 'GXTXAYB'
  i = x.length
  j = y.length
  aligned_x, aligned_y = align(x, y, i, j)
  puts "Aligned sequence 1: #{aligned_x}"
  puts "Aligned sequence 2: #{aligned_y}"
end

main