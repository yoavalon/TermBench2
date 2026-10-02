library(signal)

SignalProcessor <- setRefClass("SignalProcessor",
  fields = list(data = "numeric"),
  methods = list(
    initialize = function(data) {
      .self$data <- as.numeric(data)
    },
    apply_filter = function(kernel) {
      result <- convolve(.self$data, kernel, type = "open")
      return(result)
    },
    normalize = function(data) {
      min_val <- min(data)
      max_val <- max(data)
      normalized <- (data - min_val) / (max_val - min_val)
      return(normalized)
    }
  )
)

SequenceGenerator <- setRefClass("SequenceGenerator",
  fields = list(length = "numeric"),
  methods = list(
    initialize = function(length) {
      .self$length <- as.numeric(length)
    },
    generate_sine_wave = function(frequency, amplitude, phase) {
      t <- seq(0, 1, length.out = .self$length)
      wave <- amplitude * sin(2 * pi * frequency * t + phase)
      return(wave)
    }
  )
)

Analysis <- setRefClass("Analysis",
  fields = list(data = "numeric"),
  methods = list(
    initialize = function(processed_data) {
      .self$data <- as.numeric(processed_data)
    },
    calculate_fft = function() {
      fft_result <- fft(.self$data)
      return(fft_result)
    },
    find_peak_frequency = function(fft_result) {
      freqs <- fft.freq(length(fft_result))
      peak_idx <- which.max(abs(fft_result))
      peak_freq <- freqs[peak_idx]
      return(peak_freq)
    }
  )
)

main <- function() {
  length <- 1024
  generator <- SequenceGenerator$new(length)
  signal <- generator$generate_sine_wave(frequency = 5, amplitude = 1, phase = 0)
  processor <- SignalProcessor$new(signal)
  kernel <- c(0.25, 0.5, 0.25)
  filtered_data <- processor$apply_filter(kernel)
  normalized_data <- processor$normalize(filtered_data)
  analysis <- Analysis$new(normalized_data)
  fft_result <- analysis$calculate_fft()
  peak_frequency <- analysis$find_peak_frequency(fft_result)
  print(paste("Peak Frequency:", peak_frequency))
}

main()