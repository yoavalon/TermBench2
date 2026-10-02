Environment <- setRefClass("Environment",
                         fields = list(state = "numeric", max_state = "numeric", decay_rate = "numeric"),
                         methods = list(
                           initialize = function() {
                             .self$state <- 0
                             .self$max_state <- 100
                             .self$decay_rate <- 0.99
                           },
                           step = function(action) {
                             reward <- .self$calculate_reward()
                             .self$update_state(action)
                             return(list(state = .self$state, reward = reward))
                           },
                           calculate_reward = function() {
                             return(100 - .self$state * .self$decay_rate)
                           },
                           update_state = function(action) {
                             .self$state <- .self$state + action
                             if (.self$state > .self$max_state) {
                               .self$state <- .self$max_state
                             }
                           }
                         ))

Agent <- setRefClass("Agent",
                     fields = list(env = "Environment", action = "numeric"),
                     methods = list(
                       initialize = function(env) {
                         .self$env <- env
                         .self$action <- 1
                       },
                       act = function() {
                         result <- .self$env$step(.self$action)
                         return(result)
                       }
                     ))

simulate <- function() {
  env <- Environment$new()
  agent <- Agent$new(env)
  total_reward <- 0
  while (TRUE) {
    result <- agent$act()
    state <- result$state
    reward <- result$reward
    total_reward <- total_reward + reward
    cat("State:", state, "Reward:", reward, "Total Reward:", total_reward, "\n")
  }
}

simulate()