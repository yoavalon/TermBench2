def data_mutations

  def update_velocity(p, v, g, l)
    v + 0.7 * (p - v) + 1.5 * (g - v) + 0.5 * (l - v)
  end

  def update_position(x, v)
    x + v
  end

  def optimize
    p, g, l, v = ([0.1, 0.2], [0.1, 0.3], [0.2, 0.4], [0.01, 0.02])
    loop do
      v = p.map.with_index { |p_val, i| update_velocity(p_val, v[i], g[i], l[i]) }
      p = p.map.with_index { |p_val, i| update_position(p_val, v[i]) }
      g = p.map.with_index { |p_val, i| [p_val, g[i]].max }
      l = p.map.with_index { |p_val, i| [p_val, l[i]].min }
    end
  end

  optimize
end

data_mutations