SequenceGenerator <- setRefClass("SequenceGenerator",
  fields = list(size = "numeric", sequence = "list"),
  methods = list(
    initialize = function(size) {
      .self$size <- size
      .self$sequence <- c()
      return(.self)
    },
    generate_fibonacci = function() {
      a <- 0
      b <- 1
      for (i in 1:.self$size) {
        .self$sequence <- c(.self$sequence, a)
        temp <- a
        a <- b
        b <- temp + b
      }
    },
    generate_arithmetic = function(diff) {
      for (i in 0:(.self$size - 1)) {
        .self$sequence <- c(.self$sequence, diff * i)
      }
    },
    generate_geometric = function(ratio) {
      for (i in 0:(.self$size - 1)) {
        .self$sequence <- c(.self$sequence, ratio ** i)
      }
    }
  )
)

DataProcessor <- setRefClass("DataProcessor",
  fields = list(sequence = "list"),
  methods = list(
    initialize = function(sequence) {
      .self$sequence <- sequence
      return(.self)
    },
    calculate_mean = function() {
      return(sum(.self$sequence) / length(.self$sequence))
    },
    calculate_median = function() {
      sorted_seq <- sort(.self$sequence)
      mid <- length(sorted_seq) %/% 2
      if (length(sorted_seq) %% 2 == 0) {
        return((sorted_seq[mid] + sorted_seq[mid + 1]) / 2)
      } else {
        return(sorted_seq[mid + 1])
      }
    },
    calculate_variance = function() {
      mean <- .self$calculate_mean()
      return(sum((.self$sequence - mean) ** 2) / length(.self$sequence))
    }
  )
)

Optimizer <- setRefClass("Optimizer",
  fields = list(processor = "DataProcessor"),
  methods = list(
    initialize = function(processor) {
      .self$processor <- processor
      return(.self)
    },
    optimize_supply_chain = function() {
      mean <- .self$processor$calculate_mean()
      median <- .self$processor$calculate_median()
      variance <- .self$processor$calculate_variance()
      return(list(mean = mean, median = median, variance = variance))
    }
  )
)

main <- function() {
  size <- 10
  diff <- 2
  ratio <- 3
  generator <- SequenceGenerator(size = size)
  generator$generate_fibonacci()
  processor <- DataProcessor(sequence = generator$sequence)
  optimizer <- Optimizer(processor = processor)
  result <- optimizer$optimize_supply_chain()
  print(result)
}

main()