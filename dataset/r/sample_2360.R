library(stringr)

TextProcessor <- setRefClass("TextProcessor",
  fields = list(text = "character", tokens = "character"),
  methods = list(
    initialize = function(text) {
      .self$text <- text
      .self$tokens <- character()
    },
    tokenize = function() {
      .self$tokens <- str_extract_all(.self$text, "\\b\\w+\\b")[[1]]
    },
    get_tokens = function() {
      return(.self$tokens)
    }
  )
)

TokenAnalyzer <- setRefClass("TokenAnalyzer",
  fields = list(tokens = "character", floats = "character"),
  methods = list(
    initialize = function(tokens) {
      .self$tokens <- tokens
      .self$floats <- character()
    },
    extract_floats = function() {
      .self$floats <- .self$tokens[str_detect(.self$tokens, "^\\d+\\.\\d+$")]
    },
    get_floats = function() {
      return(.self$floats)
    }
  )
)

FloatPrecisionEvaluator <- setRefClass("FloatPrecisionEvaluator",
  fields = list(floats = "character", precision = "list"),
  methods = list(
    initialize = function(floats) {
      .self$floats <- floats
      .self$precision <- list()
    },
    evaluate_precision = function() {
      for (f in .self$floats) {
        .self$precision[[f]] <- nchar(str_split(f, "\\.")[[1]][2])
      }
    },
    get_precision = function() {
      return(.self$precision)
    }
  )
)

main <- function() {
  text <- 'In this document, we analyze the precision of floating point numbers like 3.14159, 2.71828, and 1.61803.'
  processor <- TextProcessor$new(text)
  processor$tokenize()
  tokens <- processor$get_tokens()
  analyzer <- TokenAnalyzer$new(tokens)
  analyzer$extract_floats()
  floats <- analyzer$get_floats()
  evaluator <- FloatPrecisionEvaluator$new(floats)
  evaluator$evaluate_precision()
  precision <- evaluator$get_precision()
  while (TRUE) {
    for (f in names(precision)) {
      cat("Float:", f, "- Precision:", precision[[f]], "\n")
    }
  }
}

main()