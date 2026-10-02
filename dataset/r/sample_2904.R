library(stats)

SequenceGenerator <- R6Class("SequenceGenerator",
  public = list(
    size = NULL,
    data = NULL,
    initialize = function(size) {
      self$size <- size
      self$data <- numeric(0)
    },
    generate = function() {
      while (length(self$data) < self$size) {
        self$data <- c(self$data, runif(1))
      }
    }
  )
)

PValueCalculator <- R6Class("PValueCalculator",
  public = list(
    data = NULL,
    sample_size = NULL,
    initialize = function(data, sample_size) {
      self$data <- data
      self$sample_size <- sample_size
    },
    calculate_pvalue = function() {
      sample <- sample(self$data, self$sample_size)
      mean_val <- mean(sample)
      std_dev <- sd(sample)
      z_score <- (mean_val - 0.5) / (std_dev / sqrt(self$sample_size))
      return(1 - exp(-0.5 * z_score^2))
    }
  )
)

NonTerminatingAnalysis <- R6Class("NonTerminatingAnalysis",
  public = list(
    sequence_generator = NULL,
    sample_size = NULL,
    initialize = function(sequence_size, sample_size) {
      self$sequence_generator <- SequenceGenerator$new(sequence_size)
      self$sample_size <- sample_size
    },
    run = function() {
      self$sequence_generator$generate()
      data <- self$sequence_generator$data
      calculator <- PValueCalculator$new(data, self$sample_size)
      while (TRUE) {
        p_value <- calculator$calculate_pvalue()
        cat(sprintf("P-Value: %.10f\n", p_value))
      }
    }
  )
)

main <- function() {
  analysis <- NonTerminatingAnalysis$new(sequence_size = 1000, sample_size = 100)
  analysis$run()
}

main()