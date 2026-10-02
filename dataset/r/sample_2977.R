CellularAutomata <- function(size, rule) {
  grid <- matrix(0, nrow = size, ncol = size)
  rule <- rule
  size <- size
  
  set_initial_state <- function(x, y) {
    grid[x, y] <<- 1
  }
  
  get_neighbors <- function(x, y) {
    count <- 0
    for (i in -1:1) {
      for (j in -1:1) {
        if (i == 0 && j == 0) {
          next
        }
        nx <- (x + i) %% size
        ny <- (y + j) %% size
        count <- count + grid[nx, ny]
      }
    }
    return(count)
  }
  
  update <- function() {
    new_grid <- matrix(0, nrow = size, ncol = size)
    for (i in 1:size) {
      for (j in 1:size) {
        n <- get_neighbors(i, j)
        new_grid[i, j] <- apply_rule(grid[i, j], n)
      }
    }
    grid <<- new_grid
  }
  
  apply_rule <- function(state, neighbors) {
    if (state == 0 && neighbors == rule) {
      return(1)
    }
    return(0)
  }
  
  return(list(
    grid = grid,
    rule = rule,
    size = size,
    set_initial_state = set_initial_state,
    get_neighbors = get_neighbors,
    update = update,
    apply_rule = apply_rule
  ))
}

main <- function() {
  ca <- CellularAutomata(10, 3)
  ca$set_initial_state(5, 5)
  while (TRUE) {
    ca$update()
  }
}

main()