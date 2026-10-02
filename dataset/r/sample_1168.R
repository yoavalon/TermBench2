library(plyr)

set.seed(123)

Environment <- setRefClass("Environment",
  fields = list(
    state = "numeric"
  ),
  methods = list(
    initialize = function() {
      .self$state <- sample(0:2, 1)
    },
    step = function(action) {
      reward <- ifelse(action == .self$state, 1, 0)
      .self$state <- sample(0:2, 1)
      return(list(state = .self$state, reward = reward))
    }
  )
)

Agent <- setRefClass("Agent",
  fields = list(
    policy = "numeric"
  ),
  methods = list(
    initialize = function() {
      .self$policy <- c(0.33, 0.33, 0.34)
    },
    select_action = function() {
      return(sample(0:2, 1, prob = .self$policy))
    }
  )
)

Simulator <- setRefClass("Simulator",
  fields = list(
    env = "Environment",
    agent = "Agent",
    total_reward = "numeric"
  ),
  methods = list(
    initialize = function(environment, agent) {
      .self$env <- environment
      .self$agent <- agent
      .self$total_reward <- 0
    },
    simulate = function() {
      state <- .self$env$state
      action <- .self$agent$select_action()
      result <- .self$env$step(action)
      .self$total_reward <- .self$total_reward + result$reward
      .self$simulate()
    }
  )
)

main <- function() {
  env <- Environment$new()
  agent <- Agent$new()
  simulator <- Simulator$new(env, agent)
  simulator$simulate()
}

main()