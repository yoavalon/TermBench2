CellularAutomata <- setRefClass("CellularAutomata",
  fields = list(
    size = "numeric",
    rule = "numeric",
    state = "numeric"
  ),
  methods = list(
    initialize = function(size, rule) {
      .self$size <- size
      .self$rule <- rule
      .self$state <- rep(0, size)
      .self$state[size %/% 2 + 1] <- 1
    },
    apply_rule = function(left, center, right) {
      index <- 4 * left + 2 * center + right
      return(as.integer(bitwiseShiftR(.self$rule, index) & 1))
    },
    next_generation = function() {
      new_state <- rep(0, .self$size)
      for (i in 1:.self$size) {
        left <- .self$state[(i - 1) %% .self$size + 1]
        center <- .self$state[i]
        right <- .self$state[(i + 1) %% .self$size + 1]
        new_state[i] <- .self$apply_rule(left, center, right)
      }
      .self$state <<- new_state
    },
    run = function(steps) {
      results <- list()
      for (i in 1:steps) {
        results[[i]] <- .self$state
        .self$next_generation()
      }
      return(results)
    }
  )
)

generate_sequence <- function(size, rule, steps) {
  ca <- new("CellularAutomata", size = size, rule = rule)
  return(ca$run(steps))
}

display_sequence <- function(sequence) {
  for (row in sequence) {
    cat(paste(ifelse(row == 1, "1", "0"), collapse = ""), "\n")
  }
}

main <- function() {
  size <- 31
  rule <- 30
  steps <- 10
  sequence <- generate_sequence(size, rule, steps)
  display_sequence(sequence)
}

main()