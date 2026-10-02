r
SequenceParser <- R6::R6Class("SequenceParser",
  public = list(
    data = '',
    tokens = list(),
    initialize = function() {
      self$data <- ''
      self$tokens <- list()
    },
    parse = function(text) {
      self$data <- text
      self$tokenize()
    },
    tokenize = function() {
      self$tokens <- unlist(stringr::str_extract_all(self$data, '\\b\\w+\\b'))
    }
  )
)

SequenceAnalyzer <- R6::R6Class("SequenceAnalyzer",
  public = list(
    sequence = list(),
    initialize = function() {
      self$sequence <- list()
    },
    analyze = function(tokens) {
      for (token in tokens) {
        if (grepl('^[0-9]+$', token)) {
          self$sequence <- c(self$sequence, as.integer(token))
        }
      }
    }
  )
)

SequenceGenerator <- R6::R6Class("SequenceGenerator",
  public = list(
    current = 0,
    initialize = function() {
      self$current <- 0
    },
    generate = function() {
      repeat {
        yield <- self$current
        self$current <- self$current + 1
        yield
      }
    }
  )
)

main <- function() {
  parser <- SequenceParser$new()
  analyzer <- SequenceAnalyzer$new()
  generator <- SequenceGenerator$new()
  text <- 'The quick brown fox jumps over the lazy dog 12345 67890'
  parser$parse(text)
  analyzer$analyze(parser$tokens)
  for (num in generator$generate()) {
    if (num %in% analyzer$sequence) {
      print(num)
    }
  }
}

main()