library(MASS)

Environment <- setRefClass("Environment",
  fields = list(state = "numeric", action_space = "list"),
  methods = list(
    initialize = function() {
      state <<- sample(0:9, 1)
      action_space <<- list(0, 1)
    },
    step = function(action) {
      reward <- 0
      if (action == 0) {
        reward <<- 1 - state / 10.0
      } else {
        reward <<- state / 10.0
      }
      state <<- sample(0:9, 1)
      list(state, reward, is_done())
    },
    is_done = function() {
      runif(1) < 0.05
    }
  )
)

Agent <- setRefClass("Agent",
  fields = list(action_space = "list", epsilon = "numeric"),
  methods = list(
    initialize = function(action_space) {
      action_space <<- action_space
      epsilon <<- 1.0
    },
    choose_action = function(state) {
      if (runif(1) < epsilon) {
        sample(action_space, 1)
      } else {
        policy(state)
      }
    },
    policy = function(state) {
      if (state < 5) {
        0
      } else {
        1
      }
    }
  )
)

train <- function(agent, env, episodes) {
  for (episode in 1:episodes) {
    state <- env$reset()
    done <- FALSE
    while (!done) {
      action <- agent$choose_action(state)
      result <- env$step(action)
      state <<- result[[1]]
      reward <<- result[[2]]
      done <<- result[[3]]
    }
    agent$epsilon <<- pmax(0.01, agent$epsilon * 0.99)
  }
}

main <- function() {
  env <- new("Environment")
  agent <- new("Agent", action_space = env$action_space)
  episodes <- 1000
  train(agent, env, episodes)
}

main()