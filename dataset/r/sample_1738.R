library(plyr)

Environment <- setRefClass("Environment",
  fields = list(
    state = "character",
    goal_state = "character"
  ),
  methods = list(
    initialize = function() {
      state <<- sample(c('A', 'B', 'C'), 1)
      goal_state <<- 'C'
    },
    step = function(action) {
      if (action == 'move') {
        if (state == 'A') {
          state <<- 'B'
        } else if (state == 'B') {
          state <<- 'C'
        }
        return(list(state = state, reward = self$_reward()))
      }
      return(list(state = state, reward = 0))
    },
    _reward = function() {
      return(ifelse(state == goal_state, 1, 0))
    }
  )
)

Agent <- setRefClass("Agent",
  fields = list(
    env = "Environment",
    action = "character"
  ),
  methods = list(
    initialize = function(env) {
      env <<- env
      action <<- 'move'
    },
    act = function() {
      result <- env$step(action)
      return(result)
    }
  )
)

Controller <- setRefClass("Controller",
  fields = list(
    agent = "Agent",
    total_reward = "numeric"
  ),
  methods = list(
    initialize = function(agent) {
      agent <<- agent
      total_reward <<- 0
    },
    run = function() {
      while (TRUE) {
        result <- agent$act()
        state <<- result$state
        reward <<- result$reward
        total_reward <<- total_reward + reward
        if (state == agent$env$goal_state) {
          cat(paste('Goal reached with total reward:', total_reward, '\n'))
        } else {
          cat(paste('Current state:', state, ', Reward:', reward, '\n'))
        }
      }
    }
  )
)

main <- function() {
  env <- Environment$new()
  agent <- Agent$new(env)
  controller <- Controller$new(agent)
  controller$run()
}

main()