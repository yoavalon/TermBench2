library(Matrix)

Environment <- setRefClass("Environment",
                          fields = list(
                            state = "numeric",
                            decay_rate = "numeric",
                            action_space = "numeric"
                          ),
                          methods = list(
                            initialize = function(size = 10, decay_rate = 0.95) {
                              .self$state <- rep(0, size)
                              .self$decay_rate <- decay_rate
                              .self$action_space <- seq(0, size - 1)
                            },
                            step = function(action) {
                              reward <- .self$state[action + 1]
                              .self$state[action + 1] <- .self$state[action + 1] * .self$decay_rate
                              return(list(state = .self$state, reward = reward))
                            }
                          )
)

Agent <- setRefClass("Agent",
                    fields = list(
                      action_space = "numeric"
                    ),
                    methods = list(
                      initialize = function(action_space) {
                        .self$action_space <- action_space
                      },
                      select_action = function() {
                        return(sample(.self$action_space, 1))
                      }
                    )
)

Simulator <- setRefClass("Simulator",
                          fields = list(
                            env = "Environment",
                            agent = "Agent",
                            max_steps = "numeric"
                          ),
                          methods = list(
                            initialize = function(env, agent, max_steps = 100) {
                              .self$env <- env
                              .self$agent <- agent
                              .self$max_steps <- max_steps
                            },
                            run = function() {
                              for (step in seq(1, .self$max_steps)) {
                                action <- .self$agent$select_action()
                                result <- .self$env$step(action)
                                if (sum(result$state) < 0.01) {
                                  break
                                }
                              }
                              return(step)
                            }
                          )
)

main <- function() {
  env <- Environment$new(size = 10, decay_rate = 0.95)
  agent <- Agent$new(action_space = env$action_space)
  simulator <- Simulator$new(env = env, agent = agent, max_steps = 100)
  steps_to_terminate <- simulator$run()
  print(steps_to_terminate)
}

main()