set.seed(123)

Environment <- setRefClass("Environment",
  fields = list(
    state = "numeric",
    goal = "numeric"
  ),
  methods = list(
    initialize = function() {
      .self$state <- 0
      .self$goal <- 5
    },
    step = function(action) {
      if (action == 1) {
        .self$state <- .self$state + 1
      }
      if (.self$state >= .self$goal) {
        reward <- 1
        done <- TRUE
      } else {
        reward <- -0.1
        done <- FALSE
      }
      return(list(state = .self$state, reward = reward, done = done))
    }
  )
)

Agent <- setRefClass("Agent",
  fields = list(
    epsilon = "numeric",
    alpha = "numeric",
    gamma = "numeric",
    q_table = "list"
  ),
  methods = list(
    initialize = function(epsilon, alpha, gamma) {
      .self$epsilon <- epsilon
      .self$alpha <- alpha
      .self$gamma <- gamma
      .self$q_table <- list()
    },
    select_action = function(state) {
      if (runif(1) < .self$epsilon) {
        return(sample(c(0, 1), 1))
      } else {
        if (!is.null(.self$q_table[[as.character(state)]]) && length(.self$q_table[[as.character(state)]]) == 2) {
          return(which.max(.self$q_table[[as.character(state)]]))
        } else {
          return(sample(c(0, 1), 1))
        }
      }
    },
    update_q_table = function(state, action, reward, next_state, done) {
      if (is.null(.self$q_table[[as.character(state)]]) || length(.self$q_table[[as.character(state)]]) != 2) {
        .self$q_table[[as.character(state)]] <- c(0, 0)
      }
      if (is.null(.self$q_table[[as.character(next_state)]]) || length(.self$q_table[[as.character(next_state)]]) != 2) {
        .self$q_table[[as.character(next_state)]] <- c(0, 0)
      }
      old_value <- .self$q_table[[as.character(state)]][action + 1]
      next_max <- max(.self$q_table[[as.character(next_state)]])
      new_value <- old_value + .self$alpha * (reward + .self$gamma * next_max - old_value)
      .self$q_table[[as.character(state)]][action + 1] <- new_value
    }
  )
)

main <- function() {
  env <- Environment$new()
  agent <- Agent$new(epsilon = 0.1, alpha = 0.5, gamma = 0.9)
  episodes <- 1000
  for (episode in 1:episodes) {
    state <- env$initialize()
    done <- FALSE
    while (!done) {
      action <- agent$select_action(state)
      result <- env$step(action)
      next_state <- result$state
      reward <- result$reward
      done <- result$done
      agent$update_q_table(state, action, reward, next_state, done)
      state <- next_state
    }
  }
}

main()