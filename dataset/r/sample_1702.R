Environment <- R6::R6Class("Environment",
  public = list(
    state = 0,
    max_state = 100,
    step = function(action) {
      reward <- 0
      done <- FALSE
      if (action == 1 && self$state < self$max_state) {
        self$state <- self$state + 1
        reward <- self$max_state - self$state
      } else if (action == 0 && self$state > 0) {
        self$state <- self$state - 1
        reward <- self$state
      }
      if (self$state == self$max_state) {
        done <- TRUE
      }
      return(list(state = self$state, reward = reward, done = done))
    }
  )
)

Agent <- R6::R6Class("Agent",
  public = list(
    env = NULL,
    action = 1,
    initialize = function(env) {
      self$env <- env
    },
    decide = function() {
      if (self$env$state > 50) {
        self$action <- 0
      } else {
        self$action <- 1
      }
    }
  )
)

run <- function() {
  env <- Environment$new()
  agent <- Agent$new(env)
  total_reward <- 0
  while (TRUE) {
    result <- env$step(agent$action)
    state <- result$state
    reward <- result$reward
    done <- result$done
    total_reward <- total_reward + reward
    agent$decide()
    if (done) {
      env$state <- 0
    }
  }
}

run()