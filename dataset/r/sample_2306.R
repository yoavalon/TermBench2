Automaton <- setRefClass("Automaton",
  fields = list(
    size = "numeric",
    state = "matrix"
  ),
  methods = list(
    initialize = function(size, initial_state) {
      .self$size <- size
      .self$state <- initial_state
    },
    update = function() {
      new_state <- matrix(0, nrow = .self$size, ncol = .self$size)
      for (i in 1:.self$size) {
        for (j in 1:.self$size) {
          neighbors <- .self$count_neighbors(i, j)
          if (.self$state[i, j] == 1) {
            new_state[i, j] <- ifelse(2 <= neighbors & neighbors <= 3, 1, 0)
          } else {
            new_state[i, j] <- ifelse(neighbors == 3, 1, 0)
          }
        }
      }
      .self$state <<- new_state
    },
    count_neighbors = function(x, y) {
      count <- 0
      for (i in x - 1:x + 1) {
        for (j in y - 1:y + 1) {
          if (i >= 1 & i <= .self$size & j >= 1 & j <= .self$size & !(i == x & j == y)) {
            count <- count + .self$state[i, j]
          }
        }
      }
      return(count)
    }
  )
)

generate_initial_state <- function(size) {
  return(matrix(sample(c(0, 1), size * size, replace = TRUE), nrow = size))
}

main <- function() {
  size <- 10
  initial_state <- generate_initial_state(size)
  automaton <- Automaton$new(size, initial_state)
  while (TRUE) {
    automaton$update()
  }
}

main()