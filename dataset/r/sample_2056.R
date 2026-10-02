r
FloatingPointAnalyzer <- setRefClass("FloatingPointAnalyzer",
  fields = list(precision = "numeric", data_points = "list"),
  methods = list(
    initialize = function(precision) {
      .self$precision <- precision
      .self$data_points <- list()
    },
    add_data = function(value) {
      .self$data_points <- c(.self$data_points, round(value, .self$precision))
    },
    calculate_average = function() {
      total <- sum(.self$data_points)
      count <- length(.self$data_points)
      if (count > 0) {
        return(round(total / count, .self$precision))
      } else {
        return(0)
      }
    },
    analyze = function() {
      average <- .self$calculate_average()
      variance <- .self$calculate_variance(average)
      return(list(average, variance))
    },
    calculate_variance = function(average) {
      squared_diffs <- (sapply(.self$data_points, function(x) (x - average)^2))
      if (length(.self$data_points) > 0) {
        return(round(sum(squared_diffs) / length(.self$data_points), .self$precision))
      } else {
        return(0)
      }
    }
  )
)

Ledger <- setRefClass("Ledger",
  fields = list(precision = "numeric", analyzer = "FloatingPointAnalyzer"),
  methods = list(
    initialize = function(precision) {
      .self$precision <- precision
      .self$analyzer <- FloatingPointAnalyzer(precision = precision)
    },
    record_transaction = function(value) {
      .self$analyzer$add_data(value)
    },
    get_analysis = function() {
      return(.self$analyzer$analyze())
    }
  )
)

main <- function() {
  ledger <- Ledger(precision = 4)
  ledger$record_transaction(100.1234)
  ledger$record_transaction(200.5678)
  ledger$record_transaction(300.9012)
  ledger$record_transaction(400.3456)
  ledger$record_transaction(500.789)
  analysis <- ledger$get_analysis()
  cat('Average:', analysis[[1]], 'Variance:', analysis[[2]], '\n')
}

main()