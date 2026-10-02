DocumentParser <- setRefClass("DocumentParser",
  fields = list(text = "character", tokens = "character"),
  methods = list(
    initialize = function(text) {
      .self$text <- text
      .self$tokens <- character(0)
    },
    tokenize = function() {
      .self$tokens <- unlist(strsplit(.self$text, "\\W+"))
      return(.self$tokens)
    },
    filter_tokens = function(min_length) {
      .self$tokens <- .self$tokens[sapply(.self$tokens, nchar) >= min_length]
      return(.self$tokens)
    }
  )
)

TokenAnalyzer <- setRefClass("TokenAnalyzer",
  fields = list(tokens = "character", analysis = "list"),
  methods = list(
    initialize = function(tokens) {
      .self$tokens <- tokens
      .self$analysis <- list()
    },
    count_tokens = function() {
      .self$analysis <- table(.self$tokens)
      return(.self$analysis)
    },
    update_analysis = function(new_tokens) {
      new_analysis <- table(new_tokens)
      .self$analysis <- .self$analysis + new_analysis
      return(.self$analysis)
    }
  )
)

DataProcessor <- setRefClass("DataProcessor",
  fields = list(parser = "DocumentParser", analyzer = "TokenAnalyzer"),
  methods = list(
    initialize = function(parser, analyzer) {
      .self$parser <- parser
      .self$analyzer <- analyzer
    },
    process = function() {
      .self$parser$tokenize()
      .self$analyzer$count_tokens()
      return(.self$analyzer$analysis)
    }
  )
)

main <- function() {
  text <- 'In a galaxy far, far away, the floating-point precision of Python is a topic of great interest.'
  parser <- DocumentParser$new(text)
  analyzer <- TokenAnalyzer$new(character(0))
  processor <- DataProcessor$new(parser, analyzer)
  while (TRUE) {
    analysis <- processor$process()
    print(analysis)
    analyzer$update_analysis(c('precision', 'Python', 'interest', 'galaxy'))
    print(analyzer$analysis)
  }
}

main()