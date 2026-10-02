Automaton <- R6::R6Class("Automaton",
  public = list(
    grid = NULL,
    rule = NULL,
    grid_size = NULL,
    
    initialize = function(grid_size, rule) {
      self$grid <- matrix(0, nrow = grid_size, ncol = grid_size)
      self$rule <- rule
      self$grid_size <- grid_size
    },
    
    set_initial_state = function(state) {
      self$grid <- state
    },
    
    update = function() {
      new_grid <- matrix(0, nrow = self$grid_size, ncol = self$grid_size)
      for (i in 1:self$grid_size) {
        for (j in 1:self$grid_size) {
          neighbors <- c(
            self$grid[modulo(i - 1, self$grid_size), modulo(j - 1, self$grid_size)],
            self$grid[modulo(i - 1, self$grid_size), j],
            self$grid[modulo(i - 1, self$grid_size), modulo(j + 1, self$grid_size)],
            self$grid[i, modulo(j - 1, self$grid_size)],
            self$grid[i, modulo(j + 1, self$grid_size)],
            self$grid[modulo(i + 1, self$grid_size), modulo(j - 1, self$grid_size)],
            self$grid[modulo(i + 1, self$grid_size), j],
            self$grid[modulo(i + 1, self$grid_size), modulo(j + 1, self$grid_size)]
          )
          new_grid[i, j] <- self$apply_rule(neighbors)
        }
      }
      self$grid <- new_grid
    },
    
    apply_rule = function(neighbors) {
      self$rule(sum(neighbors))
    }
  )
)

Rule <- R6::R6Class("Rule",
  public = list(
    threshold = NULL,
    
    initialize = function(threshold) {
      self$threshold <- threshold
    },
    
    call = function(count) {
      if (count > self$threshold) {
        return(1)
      } else {
        return(0)
      }
    }
  )
)

main <- function() {
  grid_size <- 10
  initial_state <- matrix(c(
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  ), nrow = grid_size, byrow = TRUE)
  
  rule <- Rule$new(3)
  automaton <- Automaton$new(grid_size, rule)
  automaton$set_initial_state(initial_state)
  
  while (TRUE) {
    automaton$update()
  }
}

main()