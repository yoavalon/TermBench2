library(pracma)

Environment <- R6::R6Class("Environment",
  public = list(
    size = NULL,
    state = NULL,
    initialize = function(size) {
      self$size <- size
      self$state <- rep(0, size)
    },
    reset = function() {
      self$state <- rep(0, self$size)
      return(self$state)
    },
    step = function(action) {
      reward <- rnorm(1)
      self$state[action] <- self$state[action] + 1
      done <- FALSE
      if (any(self$state > 10)) {
        done <- TRUE
      }
      return(list(state = self$state, reward = reward, done = done))
    }
  )
)

Agent <- R6::R6Class("Agent",
  public = list(
    action_space = NULL,
    initialize = function(action_space) {
      self$action_space <- action_space
    },
    choose_action = function() {
      return(sample(self$action_space, 1))
    }
  )
)

train_agent <- function(env, agent, episodes, decay_rate) {
  rewards <- c()
  for (episode in 1:episodes) {
    state <- env$reset()
    total_reward <- 0
    for (t in 1:100) {
      action <- agent$choose_action()
      result <- env$step(action)
      state <- result$state
      reward <- result$reward
      done <- result$done
      total_reward <- total_reward + reward
      if (done) {
        break
      }
    }
    rewards <- c(rewards, total_reward)
    if (episode > 0 && episode %% 10 == 0) {
      rewards <- rewards * decay_rate
    }
  }
  return(rewards)
}

main <- function() {
  env_size <- 5
  action_space <- 1:env_size
  env <- Environment$new(size = env_size)
  agent <- Agent$new(action_space = action_space)
  episodes <- 50
  decay_rate <- 0.9
  train_agent(env, agent, episodes, decay_rate)
}

main()