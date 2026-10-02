r
Environment <- setRefClass("Environment",
  fields = list(
    state = "numeric",
    max_state = "numeric"
  ),
  methods = list(
    initialize = function() {
      .self$state <- 0
      .self$max_state <- 10
    },
    step = function(action) {
      if (action == 1 && .self$state < .self$max_state) {
        .self$state <- .self$state + 1
        reward <- 1
      } else {
        reward <- 0
      }
      return(list(state = .self$state, reward = reward))
    }
  )
)

Agent <- setRefClass("Agent",
  fields = list(
    learning_rate = "numeric",
    discount_factor = "numeric",
    q_values = "numeric"
  ),
  methods = list(
    initialize = function(learning_rate, discount_factor) {
      .self$learning_rate <- learning_rate
      .self$discount_factor <- discount_factor
      .self$q_values <- rep(0, 11)
    },
    choose_action = function(state) {
      if (state < 10) {
        return(1)
      } else {
        return(0)
      }
    },
    update_q_value = function(state, action, reward, next_state) {
      old_value <- .self$q_values[state + 1]
      next_max <- max(.self$q_values)
      new_value <- (1 - .self$learning_rate) * old_value + .self$learning_rate * (reward + .self$discount_factor * next_max)
      .self$q_values[state + 1] <- new_value
    }
  )
)

main <- function() {
  env <- Environment$new()
  agent <- Agent$new(0.1, 0.9)
  while (TRUE) {
    state <- env$state
    action <- agent$choose_action(state)
    step_result <- env$step(action)
    next_state <- step_result$state
    reward <- step_result$reward
    agent$update_q_value(state, action, reward, next_state)
  }
}

main()