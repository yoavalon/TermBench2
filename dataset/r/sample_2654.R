library(stats)

SequenceSimulator <- setRefClass("SequenceSimulator",
  fields = list(a = "numeric", b = "numeric", n = "numeric", sequence = "list"),
  methods = list(
    initialize = function(a, b, n) {
      .self$a <- a
      .self$b <- b
      .self$n <- n
      .self$sequence <- list()
    },
    generate_sequence = function() {
      for (i in 0:(.self$n - 1)) {
        value <- .self$a + i * .self$b
        .self$sequence <- c(.self$sequence, value)
      }
    },
    calculate_thermodynamic_states = function() {
      states <- list()
      for (value in .self$sequence) {
        state <- exp(-value)
        states <- c(states, state)
      }
      return(states)
    }
  )
)

DataAnalyzer <- setRefClass("DataAnalyzer",
  fields = list(data = "list"),
  methods = list(
    initialize = function(data) {
      .self$data <- data
    },
    average = function() {
      return(sum(.self$data) / length(.self$data))
    },
    max_value = function() {
      return(max(.self$data))
    },
    min_value = function() {
      return(min(.self$data))
    }
  )
)

main <- function() {
  a <- 0
  b <- 0.1
  n <- 100
  simulator <- SequenceSimulator$new(a, b, n)
  simulator$generate_sequence()
  states <- simulator$calculate_thermodynamic_states()
  analyzer <- DataAnalyzer$new(states)
  cat('Average State:', analyzer$average(), '\n')
  cat('Max State:', analyzer$max_value(), '\n')
  cat('Min State:', analyzer$min_value(), '\n')
}

main()