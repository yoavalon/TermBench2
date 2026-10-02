StateSimulator <- setRefClass("StateSimulator",
  fields = list(
    state = "numeric",
    rules = "list"
  ),
  methods = list(
    apply_rules = function() {
      new_state <- state
      for (rule in rules) {
        if (state %in% rule[[1]]) {
          new_state <- rule[[2]](state)
          break
        }
      }
      return(new_state)
    },
    simulate = function(steps) {
      for (i in 1:steps) {
        state <<- apply_rules()
      }
    }
  )
)

RuleApplier <- setRefClass("RuleApplier",
  fields = list(
    condition = "function",
    action = "function"
  ),
  methods = list(
    call = function(state) {
      if (condition(state)) {
        return(action(state))
      }
      return(state)
    }
  )
)

condition_a <- function(state) {
  return(state < 100)
}

action_a <- function(state) {
  return(state + 10)
}

condition_b <- function(state) {
  return(state >= 100)
}

action_b <- function(state) {
  return(state - 5)
}

main <- function() {
  initial_state <- 50
  rules <- list(
    list(c("a"), RuleApplier$new(condition_a, action_a)),
    list(c("b"), RuleApplier$new(condition_b, action_b))
  )
  simulator <- StateSimulator$new(initial_state, rules)
  simulator$simulate(20)
  print(simulator$state)
}

main()