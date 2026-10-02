CellularAutomaton <- setRefClass("CellularAutomaton",
  fields = list(
    size = "numeric",
    rules = "list",
    state = "numeric"
  ),
  methods = list(
    initialize = function(size, rules) {
      .self$size <- size
      .self$rules <- rules
      .self$state <- rep(0, size)
    },
    update = function() {
      new_state <- rep(0, .self$size)
      for (i in 1:.self$size) {
        left <- ifelse(i > 1, .self$state[i - 1], .self$state[.self$size])
        right <- .self$state[(i %% .self$size) + 1]
        neighborhood <- list(left, .self$state[i], right)
        new_state[i] <- .self$rules[[do.call(paste, neighborhood)]]
      }
      .self$state <<- new_state
    },
    display = function() {
      paste(.self$state, collapse = "")
    }
  )
)

generate_rules <- function(rule_number) {
  rules <- list()
  for (i in 0:7) {
    neighborhood <- list(i %/% 4, i %/% 2 %% 2, i %% 2)
    rules[[do.call(paste, neighborhood)]] <- as.numeric(intToBits(rule_number)[i + 1])
  }
  return(rules)
}

simulate_automaton <- function(size, rule_number, steps) {
  automaton <- new("CellularAutomaton", size, generate_rules(rule_number))
  automaton$state[size %/% 2 + 1] <- 1
  for (i in 1:steps) {
    print(automaton$display())
    automaton$update()
  }
}

main <- function() {
  size <- 31
  rule_number <- 30
  steps <- 10
  simulate_automaton(size, rule_number, steps)
}

main()