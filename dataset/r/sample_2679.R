SequenceGenerator <- setRefClass("SequenceGenerator",
    fields = list(start = "numeric", end = "numeric", step = "numeric", current = "numeric"),
    methods = list(
        initialize = function(start, end, step) {
            .self$start <- start
            .self$end <- end
            .self$step <- step
            .self$current <- start
        },
        generate = function() {
            if (.self$current < .self$end) {
                value <- .self$current
                .self$current <- .self$current + .self$step
                return(value)
            }
            return(NULL)
        }
    )
)

RewardCalculator <- setRefClass("RewardCalculator",
    fields = list(decay_rate = "numeric", current_reward = "numeric"),
    methods = list(
        initialize = function(decay_rate) {
            .self$decay_rate <- decay_rate
            .self$current_reward <- 1.0
        },
        calculate = function() {
            .self$current_reward <- .self$current_reward * .self$decay_rate
            return(.self$current_reward)
        }
    )
)

process_sequence <- function() {
    seq_gen <- SequenceGenerator$start(1, 10, 1)
    reward_calc <- RewardCalculator$start(0.95)
    total_reward <- 0.0
    while (TRUE) {
        value <- seq_gen$generate()
        if (is.null(value)) {
            break
        }
        reward <- reward_calc$calculate()
        total_reward <- total_reward + reward
    }
    return(total_reward)
}

main <- function() {
    result <- process_sequence()
    print(result)
}

main()