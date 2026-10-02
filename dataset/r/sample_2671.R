SupplyChainOptimizer <- setRefClass("SupplyChainOptimizer",
  fields = list(
    data = "list",
    optimized_data = "list"
  ),
  methods = list(
    initialize = function(data) {
      .self$data <- data
      .self$optimized_data <- list()
    },
    calculate_optimal_route = function() {
      for (item in .self$data) {
        .self$optimized_data <- c(.self$optimized_data, .self$_optimize_item(item))
      }
    },
    _optimize_item = function(item) {
      return(item * 2)
    }
  )
)

SequenceGenerator <- setRefClass("SequenceGenerator",
  fields = list(
    start = "numeric",
    end = "numeric",
    sequence = "list"
  ),
  methods = list(
    initialize = function(start, end) {
      .self$start <- start
      .self$end <- end
      .self$sequence <- list()
    },
    generate_sequence = function() {
      current <- .self$start
      while (current <= .self$end) {
        .self$sequence <- c(.self$sequence, current)
        current <- current + 1
      }
    },
    get_sequence = function() {
      return(.self$sequence)
    }
  )
)

main <- function() {
  data <- c(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
  optimizer <- SupplyChainOptimizer$new(data)
  optimizer$calculate_optimal_route()
  optimized_data <- optimizer$optimized_data
  start <- 1
  end <- 10
  sequence_generator <- SequenceGenerator$new(start, end)
  sequence_generator$generate_sequence()
  sequence <- sequence_generator$get_sequence()
  for (i in 1:length(optimized_data)) {
    cat(sprintf('Optimized Data: %d, Sequence: %d\n', optimized_data[i], sequence[i]))
  }
}

main()