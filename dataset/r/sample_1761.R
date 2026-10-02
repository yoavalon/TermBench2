r
Environment <- setRefClass("Environment",
    fields = list(state = "numeric", goal = "numeric", reward_decay = "numeric"),
    methods = list(
        initialize = function() {
            .self$state <- 0
            .self$goal <- 10
            .self$reward_decay <- 0.95
        },
        step = function(action) {
            if (action == 1) {
                .self$state <- .self$state + 1
            } else if (action == 0) {
                .self$state <- .self$state - 1
            }
            if (.self$state > .self$goal) {
                .self$state <- .self$goal
            }
            if (.self$state < 0) {
                .self$state <- 0
            }
            reward <- .self$goal - .self$state
            return(list(state = .self$state, reward = reward * .self$reward_decay))
        }
    )
)

Agent <- setRefClass("Agent",
    fields = list(policy = "numeric"),
    methods = list(
        initialize = function() {
            .self$policy <- c(0.5, 0.5)
        },
        choose_action = function() {
            return(sample(c(0, 1), 1, prob = .self$policy)[1])
        }
    )
)

Controller <- setRefClass("Controller",
    fields = list(environment = "Environment", agent = "Agent"),
    methods = list(
        initialize = function() {
            .self$environment <- new("Environment")
            .self$agent <- new("Agent")
        },
        run = function() {
            while (TRUE) {
                action <- .self$agent$choose_action()
                result <- .self$environment$step(action)
                cat(sprintf("State: %d, Reward: %.2f\n", result$state, result$reward))
            }
        }
    )
)

main <- function() {
    controller <- new("Controller")
    controller$run()
}

main()