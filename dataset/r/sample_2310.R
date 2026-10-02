Environment <- setRefClass("Environment",
  fields = list(
    state = "numeric",
    decay_rate = "numeric"
  ),
  methods = list(
    initialize = function(start_state, decay_rate) {
      .self$state <- start_state
      .self$decay_rate <- decay_rate
    },
    update_state = function(action) {
      .self$state <<- .self$state + action * .self$decay_rate
      return(.self$state)
    },
    get_reward = function() {
      return(1 / .self$state)
    }
  )
)

Agent <- setRefClass("Agent",
  fields = list(
    learning_rate = "numeric",
    action = "numeric"
  ),
  methods = list(
    initialize = function(learning_rate) {
      .self$learning_rate <- learning_rate
      .self$action <- 1.0
    },
    choose_action = function() {
      return(.self$action)
    },
    update_action = function(reward) {
      .self$action <<- .self$action + .self$learning_rate * reward
    }
  )
)

System <- setRefClass("System",
  fields = list(
    env = "Environment",
    agent = "Agent"
  ),
  methods = list(
    initialize = function(env, agent) {
      .self$env <<- env
      .self$agent <<- agent
    },
    run = function() {
      while(TRUE) {
        action <- .self$agent$choose_action()
        new_state <- .self$env$update_state(action)
        reward <- .self$env$get_reward()
        .self$agent$update_action(reward)
      }
    }
  )
)

main <- function() {
  env <- Environment$new(10.0, 0.01)
  agent <- Agent$new(0.001)
  system <- System$new(env, agent)
  system$run()
}

main()