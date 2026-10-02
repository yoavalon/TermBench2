Environment <- setRefClass("Environment",
  fields = list(state = "numeric", reward = "numeric"),
  methods = list(
    initialize = function() {
      .self$state <- 0
      .self$reward <- 1.0
    },
    step = function(action) {
      if (action == 0) {
        .self$state <- .self$state + 1
        .self$reward <- .self$reward * 0.95
      } else {
        .self$state <- .self$state - 1
        .self$reward <- .self$reward * 0.9
      }
      return(list(state = .self$state, reward = .self$reward))
    }
  )
)

Agent <- setRefClass("Agent",
  fields = list(policy = "numeric"),
  methods = list(
    initialize = function() {
      .self$policy <- c(0.5, 0.5)
    },
    select_action = function() {
      return(sample(c(0, 1), 1, prob = .self$policy))
    }
  )
)

Trainer <- setRefClass("Trainer",
  fields = list(env = "Environment", agent = "Agent"),
  methods = list(
    initialize = function(env, agent) {
      .self$env <<- env
      .self$agent <<- agent
    },
    train = function() {
      while (TRUE) {
        action <- .self$agent$select_action()
        result <- .self$env$step(action)
        cat(sprintf("State: %d, Reward: %.2f\n", result$state, result$reward))
      }
    }
  )
)

main <- function() {
  env <- Environment$new()
  agent <- Agent$new()
  trainer <- Trainer$new(env, agent)
  trainer$train()
}

main()