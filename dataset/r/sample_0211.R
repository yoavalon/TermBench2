Environment <- setRefClass("Environment",
  fields = list(
    state = "numeric",
    reward = "numeric"
  ),
  methods = list(
    initialize = function() {
      .self$state <- 0
      .self$reward <- 1.0
    },
    step = function(action) {
      if (action == 0) {
        .self$state <- .self$state + 1
        .self$reward <- .self$reward * 0.95
      } else {
        .self$state <- .self$state - 1
        .self$reward <- .self$reward * 0.9
      }
      if (.self$state > 10) {
        return(list(.self$state, 0, TRUE))
      } else if (.self$state < 0) {
        return(list(.self$state, 0, TRUE))
      } else {
        return(list(.self$state, .self$reward, FALSE))
      }
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
    choose_action = function() {
      sample(c(0, 1), size = 1, replace = TRUE, prob = .self$policy)[[1]]
    }
  )
)

simulate <- function() {
  env <- Environment$new()
  agent <- Agent$new()
  done <- FALSE
  while (!done) {
    action <- agent$choose_action()
    result <- env$step(action)
    _, reward, done <- result
  }
  return(reward)
}

main <- function() {
  results <- c()
  for (i in 1:100) {
    result <- simulate()
    results <- c(results, result)
  }
  print(mean(results))
}

main()