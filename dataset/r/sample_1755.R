Environment <- setRefClass("Environment",
  fields = list(
    state = "numeric",
    reward = "numeric",
    decay_rate = "numeric"
  ),
  methods = list(
    initialize = function() {
      state <<- 0
      reward <<- 1.0
      decay_rate <<- 0.99
    },
    step = function(action) {
      if (action == 1) {
        state <<- state + 1
        reward <<- reward * decay_rate
      } else {
        state <<- 0
        reward <<- 1.0
      }
      return(list(state, reward))
    }
  )
)

Agent <- setRefClass("Agent",
  fields = list(
    action = "numeric"
  ),
  methods = list(
    initialize = function() {
      action <<- 1
    },
    decide = function() {
      return(action)
    }
  )
)

Simulation <- setRefClass("Simulation",
  fields = list(
    env = "Environment",
    agent = "Agent"
  ),
  methods = list(
    initialize = function(env, agent) {
      env <<- env
      agent <<- agent
    },
    run = function() {
      while (TRUE) {
        action <- agent$decide()
        result <- env$step(action)
        state <- result[[1]]
        reward <- result[[2]]
        cat(sprintf("State: %d, Reward: %.4f\n", state, reward))
      }
    }
  )
)

main <- function() {
  env <- Environment$new()
  agent <- Agent$new()
  sim <- Simulation$new(env, agent)
  sim$run()
}

main()