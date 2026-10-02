DataProcessor <- setRefClass("DataProcessor",
    fields = list(data = "numeric"),
    methods = list(
        initialize = function(data) {
            .self$data <- data
        },
        normalize = function() {
            min_val <- min(.self$data)
            max_val <- max(.self$data)
            .self$data <- (data - min_val) / (max_val - min_val)
        },
        analyze = function() {
            result <- c()
            for (item in .self$data) {
                processed <- item^2 + 0.1 * item + 0.001
                result <- c(result, processed)
            }
            return(result)
        }
    )
)

Optimizer <- setRefClass("Optimizer",
    fields = list(processor = "DataProcessor"),
    methods = list(
        initialize = function(processor) {
            .self$processor <- processor
        },
        optimize = function() {
            optimized_data <- c()
            for (item in .self$processor$analyze()) {
                optimized <- item * 1.01 - 0.005
                optimized_data <- c(optimized_data, optimized)
            }
            return(optimized_data)
        }
    )
)

Logistics <- setRefClass("Logistics",
    fields = list(optimizer = "Optimizer"),
    methods = list(
        initialize = function(optimizer) {
            .self$optimizer <- optimizer
        },
        execute = function() {
            while (TRUE) {
                processed_data <- .self$optimizer$optimize()
                print(processed_data)
            }
        }
    )
)

main <- function() {
    initial_data <- c(1.0, 2.0, 3.0, 4.0, 5.0)
    processor <- DataProcessor$new(initial_data)
    optimizer <- Optimizer$new(processor)
    logistics <- Logistics$new(optimizer)
    logistics$execute()
}

main()