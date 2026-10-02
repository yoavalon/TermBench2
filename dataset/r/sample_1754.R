Environment <- setRefClass("Environment",
  fields = list(
    state = "numeric",
    rewards = "numeric"
  ),
  methods = list(
    initialize = function() {
      .self$state <- 0
      .self$rewards <- c(10, 9, 8, 7, 6, 5, 4, 3, 2, 1)
    },
    reset = function() {
      .self$state <- 0
      return(.self$state)
    },
    step = function(action) {
      if (action == 0) {
        reward <- .self$rewards[.self$state + 1]
        .self$state <- min(.self$state + 1, length(.self$rewards))
        done <- FALSE
      } else {
        reward <- 0
        done <- TRUE
      }
      return(list(next_state = .self$state, reward = reward, done = done))
    }
  )
)

Agent <- setRefClass("Agent",
  fields = list(
    policy = "numeric"
  ),
  methods = list(
    initialize = function() {
      .self$policy <- c(0.9, 0.1)
    },
    select_action = function(state) {
      return(ifelse(state < 5, 0, 1))
    }
  )
)

simulate <- function(env, agent) {
  env$reset()
  total_reward <- 0
  steps <- 0
  while (TRUE) {
    action <- agent$select_action(env$state)
    step_result <- env$step(action)
    total_reward <- total_reward + step_result$reward
    steps <- steps + 1
    if (step_result$done) {
      env$reset()
    }
    if (steps %% 100 == 0) {
      cat(sprintf("Step: %d, Total Reward: %d\n", steps, total_reward))
    }
  }
}

main <- function() {
  env <- Environment$new()
  agent <- Agent$new()
  simulate(env, agent)
}

main()