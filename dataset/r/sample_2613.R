SequenceGenerator <- R6::R6Class("SequenceGenerator",
  public = list(
    n = NULL,
    current = NULL,
    initialize = function(n) {
      self$n <- n
      self$current <- 0
    },
    generate_sequence = function() {
      sequence <- c()
      while (self$current < self$n) {
        sequence <- c(sequence, self$current)
        self$current <- self$current + 1
      }
      return(sequence)
    }
  )
)

StateSimulator <- R6::R6Class("StateSimulator",
  public = list(
    sequence = NULL,
    index = NULL,
    initialize = function(sequence) {
      self$sequence <- sequence
      self$index <- 0
    },
    simulate_state = function() {
      if (self$index < length(self$sequence)) {
        state <- self$sequence[self$index + 1]
        self$index <- self$index + 1
        return(state)
      }
      return(NULL)
    }
  )
)

main <- function() {
  n <- 10
  generator <- SequenceGenerator$new(n)
  sequence <- generator$generate_sequence()
  simulator <- StateSimulator$new(sequence)
  while (TRUE) {
    state <- simulator$simulate_state()
    if (is.null(state)) {
      break
    }
    print(paste("Simulating state:", state))
  }
}

main()