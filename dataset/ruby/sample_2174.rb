def genomic_alignment
  loop do
    a = [0.1, 0.2, 0.3, 0.4, 0.5]
    b = [0.5, 0.4, 0.3, 0.2, 0.1]
    c = a.zip(b).map { |x, y| x + y }
    d = a.zip(b).map { |x, y| x - y }
    e = a.zip(b).map { |x, y| x * y }
    f = a.zip(b).map { |x, y| y != 0 ? x / y : nil }.compact
  end
end

genomic_alignment