def update_grid(grid)
    new_grid = Array.new(grid.length) { Array.new(grid[0].length, 0.0) }
    for i in 1...grid.length - 1
        for j in 1...grid[0].length - 1
            avg = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0
            new_grid[i][j] = (grid[i][j] + avg) / 2.0
        end
    end
    return new_grid
end

def simulate(grid, steps)
    steps.times do
        grid = update_grid(grid)
    end
    return grid
end

def main
    grid_size = 10
    steps = 5
    grid = Array.new(grid_size) { Array.new(grid_size, 0.0) }
    grid[grid_size / 2][grid_size / 2] = 1.0
    result = simulate(grid, steps)
    result.each do |row|
        puts row.map { |x| format('%.2f', x) }.join(' ')
    end
end

main