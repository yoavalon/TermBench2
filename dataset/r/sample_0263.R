Environment <- setRefClass("Environment",
  fields = list(
    state = "numeric",
    max_steps = "numeric",
    current_step = "numeric"
  ),
  methods = list(
    initialize = function() {
      .self$state <- 0
      .self$max_steps <- 100
      .self$current_step <- 0
    },
    reset = function() {
      .self$state <- 0
      .self$current_step <- 0
      return(.self$state)
    },
    step = function(action) {
      .self$current_step <<- .self$current_step + 1
      if (.self$current_step >= .self$max_steps) {
        done <- TRUE
      } else {
        done <- FALSE
      }
      reward <- .self$calculate_reward(action)
      .self$state <<- .self$update_state(action)
      return(list(state = .self$state, reward = reward, done = done))
    },
    calculate_reward = function(action) {
      return(ifelse(action == 0, -1, 1))
    },
    update_state = function(action) {
      return(.self$state + action)
    }
  )
)

Agent <- setRefClass("Agent",
  fields = list(
    policy = "numeric"
  ),
  methods = list(
    initialize = function() {
      .self$policy <- c(0.5, 0.5)
    },
    select_action = function() {
      return(sample(c(0, 1), 1, prob = .self$policy))
    }
  )
)

main <- function() {
  env <- Environment$new()
  agent <- Agent$new()
  total_episodes <- 10
  for (episode in 1:total_episodes) {
    state <- env$reset()
    done <- FALSE
    while (!done) {
      action <- agent$select_action()
      result <- env$step(action)
      state <- result$state
      reward <- result$reward
      done <- result$done
    }
    cat(paste("Episode", episode, "completed\n"))
  }
}

main()