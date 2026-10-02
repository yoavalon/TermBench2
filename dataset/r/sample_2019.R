library(abind)

Automaton <- setRefClass("Automaton",
    fields = list(grid = "matrix", rules = "list"),
    methods = list(
        initialize = function(size, rules) {
            .self$grid <- matrix(sample(0:1, size^2, replace = TRUE), nrow = size, ncol = size)
            .self$rules <- rules
        },
        apply_rules = function() {
            new_grid <- .self$grid
            for (i in 2:nrow(.self$grid) - 1) {
                for (j in 2:ncol(.self$grid) - 1) {
                    neighbors <- .self$grid[i-1:i+1, j-1:j+1]
                    total <- sum(neighbors)
                    if (total %in% names(.self$rules)) {
                        new_grid[i, j] <- .self$rules[[total]]
                    }
                }
            }
            .self$grid <- new_grid
        },
        update = function() {
            .self$apply_rules()
        }
    )
)

Simulation <- setRefClass("Simulation",
    fields = list(automaton = "Automaton", steps = "numeric"),
    methods = list(
        initialize = function(size, rules, steps) {
            .self$automaton <- new("Automaton", size = size, rules = rules)
            .self$steps <- steps
        },
        run = function() {
            for (i in 1:.self$steps) {
                .self$automaton$update()
            }
        }
    )
)

main <- function() {
    size <- 10
    rules <- list(`3` = 1, `12` = 1)
    steps <- 50
    simulation <- new("Simulation", size = size, rules = rules, steps = steps)
    simulation$run()
}

main()