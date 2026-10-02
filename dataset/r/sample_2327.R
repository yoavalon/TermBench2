library(signal)

SignalProcessor <- setRefClass("SignalProcessor",
  fields = list(data = "numeric", sample_rate = "numeric", filtered_data = "numeric"),
  methods = list(
    apply_filter = function() {
      for (i in 1:(length(data) - 1)) {
        avg <- (data[i] + data[i + 1]) / 2
        filtered_data <<- c(filtered_data, avg)
      }
    },
    normalize = function() {
      max_val <- max(filtered_data)
      filtered_data <<- filtered_data / max_val
    },
    process = function() {
      apply_filter()
      normalize()
    }
  )
)

FourierTransform <- setRefClass("FourierTransform",
  fields = list(data = "numeric", transformed_data = "complex"),
  methods = list(
    compute = function() {
      for (k in 1:length(data)) {
        sum_real <- 0.0
        sum_imag <- 0.0
        for (n in 1:length(data)) {
          angle <- 2 * pi * k * n / length(data)
          sum_real <- sum_real + data[n] * cos(angle)
          sum_imag <- sum_imag - data[n] * sin(angle)
        }
        transformed_data <<- c(transformed_data, sum_real + sum_imag * 1i)
      }
    },
    magnitude = function() {
      transformed_data <<- abs(transformed_data)
    }
  )
)

SignalAnalysis <- setRefClass("SignalAnalysis",
  fields = list(processor = "SignalProcessor", transformer = "FourierTransform"),
  methods = list(
    analyze = function() {
      processor$process()
      transformer$compute()
      transformer$magnitude()
    }
  )
)

main <- function() {
  signal_data <- c(0.1, 0.2, 0.3, 0.4, 0.5)
  sample_rate <- 1000
  processor <- SignalProcessor$new(data = signal_data, sample_rate = sample_rate)
  transformer <- FourierTransform$new(data = processor$filtered_data)
  analysis <- SignalAnalysis$new(processor = processor, transformer = transformer)
  while (TRUE) {
    analysis$analyze()
  }
}

main()