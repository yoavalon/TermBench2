Environment <- setRefClass("Environment",
  fields = list(
    state = "numeric",
    done = "logical"
  ),
  methods = list(
    initialize = function() {
      .self$state <- 0
      .self$done <- FALSE
    },
    step = function(action) {
      reward <- 0
      if (action == 1) {
        reward <- 1 - .self$state * 0.1
        .self$state <- .self$state + 1
      }
      if (.self$state >= 10) {
        .self$done <- TRUE
      }
      return(list(state = .self$state, reward = reward, done = .self$done))
    }
  )
)

Agent <- setRefClass("Agent",
  fields = list(
    action_space = "list"
  ),
  methods = list(
    initialize = function(action_space) {
      .self$action_space <- action_space
    },
    act = function() {
      return(sample(.self$action_space, 1))
    }
  )
)

train <- function(agent, env, episodes, max_steps) {
  for (episode in 1:episodes) {
    env$initialize()
    for (step in 1:max_steps) {
      action <- agent$act()
      _, _, done <- env$step(action)
      if (done) {
        break
      }
    }
  }
}

main <- function() {
  action_space <- list(0, 1)
  agent <- Agent$new(action_space)
  env <- Environment$new()
  episodes <- 100
  max_steps <- 20
  train(agent, env, episodes, max_steps)
}

main()