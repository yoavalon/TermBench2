CellularAutomata <- setRefClass("CellularAutomata",
    fields = list(size = "numeric", rule = "list", grid = "numeric"),
    methods = list(
        initialize = function(size, rule) {
            .self$size <- size
            .self$rule <- rule
            .self$grid <- rep(0, size)
            .self$grid[size %/% 2 + 1] <- 1
        },
        update = function() {
            new_grid <- rep(0, .self$size)
            for (i in 2:(.self$size - 1)) {
                pattern <- c(.self$grid[i - 1], .self$grid[i], .self$grid[i + 1])
                new_grid[i] <- .self$rule[[as.character(pattern)]]
            }
            .self$grid <<- new_grid
        },
        run = function(steps) {
            for (i in 1:steps) {
                .self$update()
            }
        }
    )
)

generate_rule <- function(rule_number) {
    rule <- list()
    for (i in 0:7) {
        pattern <- rev(as.numeric(intToBits(i)[8:10]))
        rule[[as.character(pattern)]] <- as.numeric(bitwAnd(bitwShiftR(rule_number, i), 1))
    }
    return(rule)
}

main <- function() {
    size <- 51
    rule_number <- 30
    steps <- 10
    rule <- generate_rule(rule_number)
    ca <- new("CellularAutomata", size = size, rule = rule)
    ca$run(steps)
    for (row in 1:(steps + 1)) {
        cat(paste(ifelse(ca$grid == 1, "#", " "), collapse = ""), "\n")
    }
}

main()