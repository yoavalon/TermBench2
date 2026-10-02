AutomataSimulator <- setRefClass(
  "AutomataSimulator",
  fields = list(
    grid = "matrix",
    rule = "list",
    size = "numeric"
  ),
  methods = list(
    initialize = function(size, rule) {
      .self$grid <- matrix(0, nrow = size, ncol = size)
      .self$rule <- rule
      .self$size <- size
    },
    update = function() {
      new_grid <- matrix(0, nrow = .self$size, ncol = .self$size)
      for (i in 1:.self$size) {
        for (j in 1:.self$size) {
          state <- .self$grid[i, j]
          neighbors <- .self$count_neighbors(i, j)
          new_state <- .self$apply_rule(state, neighbors)
          new_grid[i, j] <- new_state
        }
      }
      .self$grid <<- new_grid
    },
    count_neighbors = function(x, y) {
      count <- 0
      for (i in x - 1:x + 1) {
        for (j in y - 1:y + 1) {
          if (i >= 1 && i <= .self$size && j >= 1 && j <= .self$size && !(i == x && j == y)) {
            count <- count + .self$grid[i, j]
          }
        }
      }
      return(count)
    },
    apply_rule = function(state, neighbors) {
      return(.self$rule[[state + 1]][[neighbors + 1]])
    }
  )
)

main <- function() {
  size <- 10
  rule <- list(
    list(0 = 0, 1 = 1, 2 = 1, 3 = 1, 4 = 0, 5 = 0, 6 = 0, 7 = 0, 8 = 0),
    list(0 = 0, 1 = 0, 2 = 0, 3 = 1, 4 = 0, 5 = 0, 6 = 0, 7 = 0, 8 = 0)
  )
  automata <- AutomataSimulator(size = size, rule = rule)
  for (i in 1:100) {
    automata$update()
  }
  print(automata$grid)
}

main()